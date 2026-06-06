"""
Evolução Diferencial (DE) — interface padrão para o planejamento experimental.

Estratégia padrão : DE/rand/1/bin  (mais citada na literatura de benchmark)
Cruzamento        : binomial com j_rand garantido (garante ≥1 gene do mutante)
Clipping          : vetores mutantes são projetados de volta ao domínio [lo, hi]

Estratégias disponíveis
-----------------------
  "rand/1"           → DE/rand/1/bin       (padrão)
  "rand/2"           → DE/rand/2/bin
  "best/1"           → DE/best/1/bin
  "best/2"           → DE/best/2/bin
  "current-to-best/1"→ DE/current-to-best/1/bin

Interface pública
-----------------
de(func, dim, bounds, max_fes, pop_size, seed, estrategia, F, CR) -> dict

  func      : callable (f: np.ndarray (N,D) -> np.ndarray (N,))
  dim       : int — número de dimensões
  bounds    : (float, float) — (lower, upper) — mesmo bound para todas as dims
  max_fes   : int — orçamento de avaliações (ex.: 10_000 * dim)
  pop_size  : int — tamanho da população (padrão 100)
  seed      : int — semente para reprodutibilidade
  estrategia: str — variante de mutação (padrão "rand/1")
  F         : float — fator de escala da mutação (padrão 0.9)
  CR        : float — taxa de cruzamento binomial (padrão 0.9)

Retorna dict com:
  best_f      : float — melhor fitness encontrado
  best_x      : np.ndarray (dim,) — vetor solução
  history     : np.ndarray — melhor f* ao fim de cada geração (~pop_size FEs)
  fes_history : np.ndarray — nº acumulado de avaliações correspondente a cada ponto
  n_fes       : int — avaliações totais realizadas
"""

import numpy as np


# ── estratégias de mutação ────────────────────────────────────────────────────

def _rand_1(pop, fit, i, F, rng):
    """DE/rand/1: v = x_r0 + F·(x_r1 − x_r2)"""
    idxs = [j for j in range(len(pop)) if j != i]
    r0, r1, r2 = rng.choice(idxs, 3, replace=False)
    return pop[r0] + F * (pop[r1] - pop[r2])


def _rand_2(pop, fit, i, F, rng):
    """DE/rand/2: v = x_r0 + F·(x_r1−x_r2) + F·(x_r3−x_r4)"""
    idxs = [j for j in range(len(pop)) if j != i]
    r0, r1, r2, r3, r4 = rng.choice(idxs, 5, replace=False)
    return pop[r0] + F * (pop[r1] - pop[r2]) + F * (pop[r3] - pop[r4])


def _best_1(pop, fit, i, F, rng):
    """DE/best/1: v = x_best + F·(x_r1 − x_r2)"""
    best = pop[np.argmin(fit)]
    idxs = [j for j in range(len(pop)) if j != i]
    r1, r2 = rng.choice(idxs, 2, replace=False)
    return best + F * (pop[r1] - pop[r2])


def _best_2(pop, fit, i, F, rng):
    """DE/best/2: v = x_best + F·(x_r1−x_r2) + F·(x_r3−x_r4)"""
    best = pop[np.argmin(fit)]
    idxs = [j for j in range(len(pop)) if j != i]
    r1, r2, r3, r4 = rng.choice(idxs, 4, replace=False)
    return best + F * (pop[r1] - pop[r2]) + F * (pop[r3] - pop[r4])


def _current_to_best_1(pop, fit, i, F, rng):
    """DE/current-to-best/1: v = x_i + F·(x_best−x_i) + F·(x_r1−x_r2)"""
    best = pop[np.argmin(fit)]
    idxs = [j for j in range(len(pop)) if j != i]
    r1, r2 = rng.choice(idxs, 2, replace=False)
    return pop[i] + F * (best - pop[i]) + F * (pop[r1] - pop[r2])


_ESTRATEGIAS = {
    "rand/1"            : _rand_1,
    "rand/2"            : _rand_2,
    "best/1"            : _best_1,
    "best/2"            : _best_2,
    "current-to-best/1" : _current_to_best_1,
}


# ── cruzamento binomial ───────────────────────────────────────────────────────

def _cruzamento_binomial(target, mutant, CR, rng):
    """
    Cruzamento binomial com j_rand garantido:
    pelo menos um gene vem sempre do vetor mutante.
    """
    d      = len(target)
    j_rand = int(rng.integers(0, d))
    mask   = rng.random(d) < CR
    mask[j_rand] = True
    return np.where(mask, mutant, target)


# ── interface pública ─────────────────────────────────────────────────────────

def de(func, dim, bounds, max_fes, pop_size=100, seed=None,
       estrategia="rand/1", F=0.9, CR=0.9):
    """
    Executa a Evolução Diferencial e retorna um dicionário de resultados.

    O histórico é registrado a cada geração completa (~pop_size avaliações),
    mantendo granularidade equivalente à do AG para facilitar comparação.

    Parâmetros
    ----------
    func       : callable — função objetivo vetorizada (N, D) -> (N,)
    dim        : int      — dimensionalidade
    bounds     : (lo, hi) — domínio de busca
    max_fes    : int      — orçamento de avaliações de função
    pop_size   : int      — tamanho da população (padrão 100)
    seed       : int|None — semente RNG
    estrategia : str      — variante de mutação (padrão "rand/1")
    F          : float    — fator de escala (padrão 0.9)
    CR         : float    — taxa de cruzamento (padrão 0.9)

    Retorna
    -------
    dict com chaves: best_f, best_x, history, fes_history, n_fes
    """
    if estrategia not in _ESTRATEGIAS:
        raise ValueError(
            f"Estratégia '{estrategia}' inválida. "
            f"Opções: {list(_ESTRATEGIAS.keys())}"
        )

    mutacao_fn = _ESTRATEGIAS[estrategia]
    lo, hi = bounds
    rng = np.random.default_rng(seed)

    # ── inicialização ─────────────────────────────────────────────────────────
    pop = rng.uniform(lo, hi, (pop_size, dim))
    fit = func(pop)                        # avaliação vetorizada (pop_size FEs)
    n_fes = pop_size

    best_idx = int(np.argmin(fit))
    best_f   = float(fit[best_idx])
    best_x   = pop[best_idx].copy()

    # marco de geração: salva histórico a cada pop_size avaliações
    prox_marco = pop_size + pop_size
    history     = [best_f]
    fes_history = [n_fes]

    # ── loop principal ────────────────────────────────────────────────────────
    while n_fes < max_fes:
        for i in range(pop_size):
            if n_fes >= max_fes:
                break

            # mutação + clipping
            mutant = mutacao_fn(pop, fit, i, F, rng)
            mutant = np.clip(mutant, lo, hi)

            # cruzamento binomial
            trial = _cruzamento_binomial(pop[i], mutant, CR, rng)

            # seleção greedy (avalia 1 indivíduo por vez)
            f_trial = float(func(trial.reshape(1, -1))[0])
            n_fes += 1

            if f_trial <= fit[i]:
                pop[i] = trial
                fit[i] = f_trial

            if fit[i] < best_f:
                best_f = float(fit[i])
                best_x = pop[i].copy()

        # ── registra ao final de cada geração completa ────────────────────
        history.append(best_f)
        fes_history.append(n_fes)

    return {
        "best_f"     : best_f,
        "best_x"     : best_x,
        "history"    : np.array(history),
        "fes_history": np.array(fes_history),
        "n_fes"      : n_fes,
    }