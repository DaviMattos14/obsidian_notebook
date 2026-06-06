"""
Algoritmo Genético — interface padrão para o planejamento experimental.

Operadores (idênticos ao Tarefa_3):
  Seleção     : Torneio (k=3)
  Cruzamento  : BLX-α  (α=0.3)
  Mutação     : Creep  (taxa=0.05, σ=0.1)
  Critério    : Nº máximo de avaliações de função (max_fes)

Interface pública
-----------------
ag(func, dim, bounds, max_fes, pop_size, seed) -> dict

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


# ── operadores internos ───────────────────────────────────────────────────────

def _criar_populacao(dim, pop_size, lo, hi, rng):
    return rng.uniform(lo, hi, size=(pop_size, dim))


def _fitness(pop, func):
    """Avalia a população inteira de forma vetorizada."""
    return func(pop)


def _torneio(pop, fit, k, rng):
    """Seleciona um pai por torneio de tamanho k."""
    idx = rng.choice(len(pop), size=k, replace=False)
    vencedor = idx[np.argmin(fit[idx])]
    return pop[vencedor]


def _cruzamento_blx(p1, p2, alpha, rng):
    """BLX-α: filho gerado no intervalo [cmin - α·Δ, cmax + α·Δ]."""
    cmin = np.minimum(p1, p2)
    cmax = np.maximum(p1, p2)
    delta = cmax - cmin
    lower = cmin - alpha * delta
    upper = cmax + alpha * delta
    return lower + rng.random(size=p1.shape) * (upper - lower)


def _mutacao_creep(individuo, taxa, sigma, rng):
    """Creep mutation: perturbação gaussiana gene a gene."""
    mask = rng.random(size=individuo.shape) < taxa
    individuo = individuo.copy()
    individuo[mask] += rng.normal(0.0, sigma, size=mask.sum())
    return individuo


# ── interface pública ─────────────────────────────────────────────────────────

def ag(func, dim, bounds, max_fes, pop_size=100, seed=None,
       k_torneio=3, alpha_blx=0.3, taxa_mutacao=0.05, sigma_mutacao=0.1):
    """
    Executa o Algoritmo Genético e retorna um dicionário de resultados.

    Parâmetros
    ----------
    func         : callable — função objetivo vetorizada (N, D) -> (N,)
    dim          : int      — dimensionalidade
    bounds       : (lo, hi) — domínio de busca (igual para todas as dimensões)
    max_fes      : int      — orçamento de avaliações de função
    pop_size     : int      — tamanho da população (padrão 100)
    seed         : int|None — semente RNG
    k_torneio    : int      — participantes no torneio (padrão 3)
    alpha_blx    : float    — parâmetro α do BLX-α (padrão 0.3)
    taxa_mutacao : float    — probabilidade de mutação por gene (padrão 0.05)
    sigma_mutacao: float    — desvio-padrão do ruído creep (padrão 0.1)

    Retorna
    -------
    dict com chaves: best_f, best_x, history, fes_history, n_fes
    """
    lo, hi = bounds
    rng = np.random.default_rng(seed)

    # ── inicialização ─────────────────────────────────────────────────────────
    pop = _criar_populacao(dim, pop_size, lo, hi, rng)
    fit = _fitness(pop, func)
    n_fes = pop_size

    best_idx = int(np.argmin(fit))
    best_f   = float(fit[best_idx])
    best_x   = pop[best_idx].copy()

    history     = [best_f]
    fes_history = [n_fes]

    # ── loop geracional ───────────────────────────────────────────────────────
    while n_fes < max_fes:
        nova_pop = np.empty_like(pop)

        for i in range(pop_size):
            p1 = _torneio(pop, fit, k_torneio, rng)
            p2 = _torneio(pop, fit, k_torneio, rng)
            filho = _cruzamento_blx(p1, p2, alpha_blx, rng)
            filho = _mutacao_creep(filho, taxa_mutacao, sigma_mutacao, rng)
            nova_pop[i] = filho

        pop = nova_pop
        fit = _fitness(pop, func)
        n_fes += pop_size

        gen_best_idx = int(np.argmin(fit))
        gen_best_f   = float(fit[gen_best_idx])

        if gen_best_f < best_f:
            best_f = gen_best_f
            best_x = pop[gen_best_idx].copy()

        history.append(best_f)
        fes_history.append(n_fes)

    return {
        "best_f"     : best_f,
        "best_x"     : best_x,
        "history"    : np.array(history),
        "fes_history": np.array(fes_history),
        "n_fes"      : n_fes,
    }