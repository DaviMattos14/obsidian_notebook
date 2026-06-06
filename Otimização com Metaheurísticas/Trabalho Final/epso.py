"""
Evolutionary Particle Swarm Optimization (EPSO) — interface padrão para o planejamento experimental.

Híbrido PSO + Estratégia Evolutiva:
  - PSO clássico com dinâmica de velocidade
  - Parâmetros adaptativos (wi, em, wc) com mutação por geração
  - Mutação via distribuição normal com decaimento exponencial

Parâmetros padrão:
  pc (prob. cruzamento): 0.5
  tau (taxa de mutação): 1.0 / sqrt(2*dim)

Limite de velocidade: 20% do intervalo [lo, hi]

Interface pública
-----------------
epso(func, dim, bounds, max_fes, pop_size, seed) -> dict

  func     : callable (f: np.ndarray (N,D) -> np.ndarray (N,))
  dim      : int — número de dimensões
  bounds   : (float, float) — (lower, upper) — mesmo bound para todas as dims
  max_fes  : int — orçamento de avaliações (ex.: 10_000 * dim)
  pop_size : int — tamanho da população
  seed     : int — semente para reprodutibilidade

Retorna dict com:
  best_f      : float — melhor fitness encontrado
  best_x      : np.ndarray (dim,) — vetor solução
  history     : np.ndarray — melhor f* ao fim de cada geração
  fes_history : np.ndarray — nº acumulado de avaliações correspondente a cada ponto do history
  n_fes       : int — avaliações totais realizadas
"""

import numpy as np


def epso(func, dim, bounds, max_fes, pop_size=100, seed=None,
         pc=0.5, tau_factor=1.0):
    """
    Executa Evolutionary Particle Swarm Optimization e retorna um dicionário de resultados.

    Parâmetros
    ----------
    func       : callable — função objetivo vetorizada (N, D) -> (N,)
    dim        : int      — dimensionalidade
    bounds     : (lo, hi) — domínio de busca
    max_fes    : int      — orçamento de avaliações de função
    pop_size   : int      — tamanho da população (padrão 100)
    seed       : int|None — semente RNG
    pc         : float    — probabilidade de cruzamento (padrão 0.5)
    tau_factor : float    — fator de taxa de mutação (padrão 1.0)

    Retorna
    -------
    dict com chaves: best_f, best_x, history, fes_history, n_fes
    """
    lo, hi = bounds
    rng = np.random.default_rng(seed)

    # ── inicialização ─────────────────────────────────────────────────────────
    pop = rng.uniform(lo, hi, (pop_size, dim))
    fit = func(pop)  # avaliação vetorizada (pop_size FEs)
    n_fes = pop_size

    best_idx = int(np.argmin(fit))
    best_f = float(fit[best_idx])
    best_x = pop[best_idx].copy()

    # pbest (melhor posição pessoal de cada partícula)
    pbest = pop.copy()
    pbest_fit = fit.copy()

    # gbest (melhor posição global)
    gbest = pop[best_idx].copy()
    gbest_fit = best_f

    # velocidades iniciais
    v_max = 0.2 * (hi - lo)
    v = rng.uniform(-v_max, v_max, (pop_size, dim))

    # parâmetros adaptativos por partícula
    wi = rng.uniform(0.4, 0.9, pop_size)  # inércia
    em = np.full(pop_size, 1.5)  # aceleração pessoal
    wc = np.full(pop_size, 1.5)  # aceleração cognitiva

    # taxa de mutação
    tau = tau_factor / np.sqrt(2.0 * dim)

    # histórico de convergência (por geração)
    history = [best_f]
    fes_history = [n_fes]

    # ── loop principal ────────────────────────────────────────────────────────
    while n_fes < max_fes:
        for i in range(pop_size):
            if n_fes >= max_fes:
                break

            # ── mutação de parâmetros (estratégia evolutiva) ──────────────────
            wi_filho = wi[i] * np.exp(-tau * n_fes)
            em_filho = em[i] * np.exp(-tau * n_fes)
            wc_filho = wc[i] * np.exp(-tau * n_fes)

            # clips nos parâmetros
            wi_filho = np.clip(wi_filho, 0.4, 0.9)
            em_filho = np.clip(em_filho, 0.5, 2.5)
            wc_filho = np.clip(wc_filho, 0.5, 2.5)

            # ── cruzamento probabilístico ──────────────────────────────────────
            matriz_c = (rng.random(dim) < pc).astype(float)

            # ── atualizar velocidade ───────────────────────────────────────────
            r1 = rng.random(dim)
            r2 = rng.random(dim)

            v_filho = (
                wi_filho * v[i]
                + em_filho * r1 * (pbest[i] - pop[i])
                + wc_filho * matriz_c * r2 * (gbest - pop[i])
            )

            # limitar velocidade
            v_filho = np.clip(v_filho, -v_max, v_max)

            # ── atualizar posição ──────────────────────────────────────────────
            candidato = np.clip(pop[i] + v_filho, lo, hi)

            # ── avaliar candidato ──────────────────────────────────────────────
            fit_candidato = float(func(candidato.reshape(1, -1))[0])
            n_fes += 1

            # ── seleção greedy com adaptação de parâmetros ──────────────────────
            if fit_candidato < fit[i]:
                pop[i] = candidato
                fit[i] = fit_candidato
                v[i] = v_filho

                # atualizar parâmetros adaptativos
                wi[i] = wi_filho
                em[i] = em_filho
                wc[i] = wc_filho

                # atualizar pbest
                if fit[i] < pbest_fit[i]:
                    pbest_fit[i] = fit[i]
                    pbest[i] = pop[i].copy()

                    # atualizar gbest
                    if fit[i] < gbest_fit:
                        gbest_fit = fit[i]
                        gbest = pop[i].copy()

        # ── registra ao final de cada geração completa ────────────────────
        best_f = gbest_fit
        best_x = gbest.copy()
        history.append(best_f)
        fes_history.append(n_fes)

    return {
        "best_f": best_f,
        "best_x": best_x,
        "history": np.array(history),
        "fes_history": np.array(fes_history),
        "n_fes": n_fes,
    }
