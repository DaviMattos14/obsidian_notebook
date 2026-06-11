"""
Evolutionary Particle Swarm Optimization (EPSO)

Híbrido PSO + Estratégia Evolutiva (Miranda & Fonseca, 2002):
  - Para cada partícula, um clone é criado e tem seus pesos estratégicos mutados
  - Clone e original se movem; o melhor sobrevive (seleção greedy)
  - Pesos adaptativos (wi, em, wc, perturbation) com mutação gaussiana
  - Comunicação estocástica por dimensão: gBest só entra com prob. commProb
  - gBest é perturbado de forma independente por cada partícula antes do movimento

Parâmetros padrão:
  comm_prob (prob. comunicação por dimensão): 0.2
  tau (taxa de mutação dos pesos):            0.2

Limite de velocidade: range do espaço de busca (|hi - lo|)

Interface pública
-----------------
epso(func, dim, bounds, max_fes, pop_size, seed) -> dict

  func      : callable (f: np.ndarray (N,D) -> np.ndarray (N,))
  dim       : int — número de dimensões
  bounds    : (float, float) — (lower, upper) — mesmo bound para todas as dims
  max_fes   : int — orçamento de avaliações (ex.: 10_000 * dim)
  pop_size  : int — tamanho da população
  seed      : int — semente para reprodutibilidade

Retorna dict com:
  best_f      : float — melhor fitness encontrado
  best_x      : np.ndarray (dim,) — vetor solução
  history     : np.ndarray — melhor f* ao fim de cada geração
  fes_history : np.ndarray — nº acumulado de avaliações correspondente a cada ponto do history
  n_fes       : int — avaliações totais realizadas
"""

import numpy as np


def epso(func, dim, bounds, max_fes, pop_size=20, seed=None, comm_prob=0.2, tau=0.2):
    """
    Executa Evolutionary Particle Swarm Optimization e retorna um dicionário de resultados.

    Parâmetros
    ----------
    func      : callable — função objetivo vetorizada (N, D) -> (N,)
    dim       : int      — dimensionalidade
    bounds    : (lo, hi) — domínio de busca (uniforme por dimensão)
    max_fes   : int      — orçamento de avaliações de função
    pop_size  : int      — tamanho da população (padrão 20)
    seed      : int|None — semente RNG
    comm_prob : float    — probabilidade de comunicação por dimensão (padrão 0.2)
    tau       : float    — taxa de mutação dos pesos estratégicos (padrão 0.2)

    Retorna
    -------
    dict com chaves: best_f, best_x, history, fes_history, n_fes
    """
    lo, hi = bounds
    rng = np.random.default_rng(seed)

    v_max = float(np.abs(hi - lo))  # limite de velocidade = range do espaço

    # ── inicialização ─────────────────────────────────────────────────────────
    pop = rng.uniform(lo, hi, (pop_size, dim))
    vel = rng.uniform(-v_max, v_max, (pop_size, dim))

    fit = func(pop)  # (pop_size,) avaliações vetorizadas
    n_fes = pop_size

    # pbest
    pbest = pop.copy()
    pbest_fit = fit.copy()

    # gbest
    best_idx = int(np.argmin(fit))
    gbest_fit = float(fit[best_idx])
    gbest = pop[best_idx].copy()

    # pesos estratégicos por partícula  [wi, em, wc, perturbation]
    weights = rng.uniform(0.0, 1.0, (pop_size, 4))
    # wi=col0, em=col1, wc=col2, perturbation=col3

    history = [gbest_fit]
    fes_history = [n_fes]

    # ── loop principal ────────────────────────────────────────────────────────
    while n_fes < max_fes:

        # ── verificar e atualizar gbest (lista já "ordenada" implicitamente) ──
        best_now = int(np.argmin(pbest_fit))
        if pbest_fit[best_now] < gbest_fit:
            gbest_fit = float(pbest_fit[best_now])
            gbest = pbest[best_now].copy()

        # ── processar cada partícula ──────────────────────────────────────────
        for i in range(pop_size):
            if n_fes >= max_fes:
                break

            # ── mutação gaussiana dos pesos (clone herda pesos mutados) ────────
            noise = rng.standard_normal(4)
            w_clone = weights[i] + noise * tau
            w_clone = np.clip(w_clone, 0.0, 1.0)  # mesma lógica do C++

            wi_c   = w_clone[0]
            em_c   = w_clone[1]
            wc_c   = w_clone[2]
            pert_c = w_clone[3]

            # ── perturbação do gBest (por partícula, uma vez para todas as dims)
            disturbator = rng.uniform(0.0, 1.0)  # único sorteio, como no C++
            gbest_perturbed = gbest.copy()

            # máscara de comunicação estocástica por dimensão (Bernoulli)
            comm_mask = rng.uniform(0.0, 1.0, dim) < comm_prob  # (dim,) bool

            # aplica perturbação somente nas dimensões com comunicação ativa
            gbest_perturbed[comm_mask] = (
                gbest[comm_mask] * (1.0 + pert_c * disturbator)
            )

            # ── atualização de velocidade do clone ────────────────────────────
            r1 = rng.uniform(0.0, 1.0, dim)
            r2 = rng.uniform(0.0, 1.0, dim)

            coop_term = np.where(
                comm_mask,
                wc_c * r2 * (gbest_perturbed - pop[i]),
                0.0,
            )

            v_clone = (
                wi_c * vel[i]
                + em_c * r1 * (pbest[i] - pop[i])
                + coop_term
            )
            v_clone = np.clip(v_clone, -v_max, v_max)

            # ── atualização de posição do clone ───────────────────────────────
            pos_clone = pop[i] + v_clone

            # bounce nas fronteiras (mesmo comportamento do C++)
            mask_lo = pos_clone < lo
            mask_hi = pos_clone > hi
            pos_clone = np.clip(pos_clone, lo, hi)
            v_clone[mask_lo | mask_hi] *= -1.0
            v_clone = np.clip(v_clone, -v_max, v_max)

            fit_clone = float(func(pos_clone.reshape(1, -1))[0])
            n_fes += 1

            if n_fes >= max_fes:
                # ainda compara antes de sair
                if fit_clone < fit[i]:
                    pop[i] = pos_clone
                    vel[i] = v_clone
                    fit[i] = fit_clone
                    weights[i] = w_clone
                    if fit[i] < pbest_fit[i]:
                        pbest_fit[i] = fit[i]
                        pbest[i] = pop[i].copy()
                        if fit[i] < gbest_fit:
                            gbest_fit = fit[i]
                            gbest = pop[i].copy()
                break

            # ── movimento do original (com seus pesos não mutados) ────────────
            wi_o   = weights[i, 0]
            em_o   = weights[i, 1]
            wc_o   = weights[i, 2]
            pert_o = weights[i, 3]

            gbest_perturbed_o = gbest.copy()
            disturbator_o = rng.uniform(0.0, 1.0)
            comm_mask_o = rng.uniform(0.0, 1.0, dim) < comm_prob
            gbest_perturbed_o[comm_mask_o] = (
                gbest[comm_mask_o] * (1.0 + pert_o * disturbator_o)
            )

            r1_o = rng.uniform(0.0, 1.0, dim)
            r2_o = rng.uniform(0.0, 1.0, dim)

            coop_term_o = np.where(
                comm_mask_o,
                wc_o * r2_o * (gbest_perturbed_o - pop[i]),
                0.0,
            )

            v_orig = (
                wi_o * vel[i]
                + em_o * r1_o * (pbest[i] - pop[i])
                + coop_term_o
            )
            v_orig = np.clip(v_orig, -v_max, v_max)

            pos_orig = pop[i] + v_orig
            mask_lo_o = pos_orig < lo
            mask_hi_o = pos_orig > hi
            pos_orig = np.clip(pos_orig, lo, hi)
            v_orig[mask_lo_o | mask_hi_o] *= -1.0
            v_orig = np.clip(v_orig, -v_max, v_max)

            fit_orig = float(func(pos_orig.reshape(1, -1))[0])
            n_fes += 1

            # ── seleção greedy: melhor entre clone e original ─────────────────
            if fit_orig <= fit_clone:
                pop[i]     = pos_orig
                vel[i]     = v_orig
                fit[i]     = fit_orig
                # pesos do original permanecem (weights[i] não muda)
            else:
                pop[i]     = pos_clone
                vel[i]     = v_clone
                fit[i]     = fit_clone
                weights[i] = w_clone   # clone venceu — adota pesos mutados

            # atualiza pbest e gbest se necessário
            if fit[i] < pbest_fit[i]:
                pbest_fit[i] = fit[i]
                pbest[i] = pop[i].copy()
                if fit[i] < gbest_fit:
                    gbest_fit = fit[i]
                    gbest = pop[i].copy()

        # ── fim da geração: registra convergência ─────────────────────────────
        history.append(gbest_fit)
        fes_history.append(n_fes)

    return {
        "best_f":      gbest_fit,
        "best_x":      gbest.copy(),
        "history":     np.array(history),
        "fes_history": np.array(fes_history),
        "n_fes":       n_fes,
    }