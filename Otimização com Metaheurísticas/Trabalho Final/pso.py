"""
Particle Swarm Optimization (PSO) — interface padrão para o planejamento experimental.

Parâmetros padrão (PSO clássico):
  w (inércia)    : 0.7298
  c1, c2 (aceleração) : 1.49618 cada

Limite de velocidade : 20% do intervalo [lo, hi]

Interface pública
-----------------
pso(func, dim, bounds, max_fes, pop_size, seed) -> dict

  func     : callable (f: np.ndarray (N,D) -> np.ndarray (N,))
  dim      : int — número de dimensões
  bounds   : (float, float) — (lower, upper) — mesmo bound para todas as dims
  max_fes  : int — orçamento de avaliações (ex.: 10_000 * dim)
  pop_size : int — tamanho da população
  seed     : int — semente para reprodutibilidade

Retorna dict com:
  best_f      : float — melhor fitness encontrado
  best_x      : np.ndarray (dim,) — vetor solução
  history     : np.ndarray — melhor f* ao fim de cada geração (ou ao esgotar max_fes)
  fes_history : np.ndarray — nº acumulado de avaliações correspondente a cada ponto do history
  n_fes       : int — avaliações totais realizadas
"""

import numpy as np


def pso(func, dim, bounds, max_fes, pop_size=100, seed=None,
        w=0.7298, c1=1.49618, c2=1.49618):
    """
    Executa Particle Swarm Optimization e retorna um dicionário de resultados.

    Parâmetros
    ----------
    func     : callable — função objetivo vetorizada (N, D) -> (N,)
    dim      : int      — dimensionalidade
    bounds   : (lo, hi) — domínio de busca
    max_fes  : int      — orçamento de avaliações de função
    pop_size : int      — tamanho da população (padrão 100)
    seed     : int|None — semente RNG
    w        : float    — coeficiente de inércia (padrão 0.7298)
    c1, c2   : float    — coeficientes de aceleração (padrão 1.49618 cada)

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
    v_max = 0.2 * (hi - lo)  # limite: 20% do intervalo
    v = rng.uniform(-v_max, v_max, (pop_size, dim))

    # histórico de convergência (por geração)
    history = [best_f]
    fes_history = [n_fes]

    # ── loop principal ────────────────────────────────────────────────────────
    while n_fes < max_fes:
        for i in range(pop_size):
            if n_fes >= max_fes:
                # ── orçamento esgotado no meio de uma geração ─────────────
                # registra o ponto exato antes de sair, evitando que o último
                # entry do histórico represente uma geração incompleta sem
                # o n_fes correspondente correto.
                history.append(gbest_fit)
                fes_history.append(n_fes)
                break

            # atualizar velocidade
            r1 = rng.random(dim)
            r2 = rng.random(dim)
            v[i] = (
                w * v[i]
                + c1 * r1 * (pbest[i] - pop[i])
                + c2 * r2 * (gbest - pop[i])
            )

            # limitar velocidade
            v[i] = np.clip(v[i], -v_max, v_max)

            # atualizar posição
            pop[i] = np.clip(pop[i] + v[i], lo, hi)

            # reavaliar fitness
            fit[i] = float(func(pop[i].reshape(1, -1))[0])
            n_fes += 1

            # atualizar pbest
            if fit[i] < pbest_fit[i]:
                pbest_fit[i] = fit[i]
                pbest[i] = pop[i].copy()

                # atualizar gbest
                if fit[i] < gbest_fit:
                    gbest_fit = fit[i]
                    gbest = pop[i].copy()

        else:
            # ── registra ao final de cada geração completa ────────────────
            history.append(gbest_fit)
            fes_history.append(n_fes)

    best_f = gbest_fit
    best_x = gbest.copy()

    return {
        "best_f": best_f,
        "best_x": best_x,
        "history": np.array(history),
        "fes_history": np.array(fes_history),
        "n_fes": n_fes,
    }