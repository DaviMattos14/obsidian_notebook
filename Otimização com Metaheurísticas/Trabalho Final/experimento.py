"""
experimento.py
==============
Pipeline experimental para comparação de metaheurísticas em funções de benchmark.

Uso
---
    python experimento.py                    # roda com AG (padrão)
    python experimento.py --algoritmo ag     # explícito
    python experimento.py --dry-run          # 1 rodada por combo para testar

Estrutura dos arquivos gerados
-------------------------------
results/
  ag_resultados.csv        ← métricas resumidas (1 linha por rodada)
  ag_historico.csv         ← curvas de convergência (1 linha por geração)
"""

import argparse
import time
from itertools import product
from pathlib import Path

import numpy as np
import pandas as pd
from tqdm import tqdm

# ── funções de benchmark ──────────────────────────────────────────────────────
from benchmark import (
    sphere, rosenbrock, sum_squares, dixon_price, zakharov,
    rastrigin, ackley, griewank, schwefel, levy,
)

# ── algoritmos disponíveis ────────────────────────────────────────────────────
from ag import ag as _ag
from de import de as _de
from pso import pso as _pso
from epso import epso as _epso

ALGORITMOS = {
    "ag": _ag,
    "de": _de,
    "pso": _pso,
    "epso": _epso,
    # adicione aqui os próximos: "deepso": _deepso, "cdeepso": _cdeepso, ...
}

# ── configuração experimental ─────────────────────────────────────────────────
FUNCOES = {
    # nome           callable       (lo, hi)
    "sphere"      : (sphere,      (-100.0, 100.0)),
    "rosenbrock"  : (rosenbrock,  (  -5.0,  10.0)),
    "sum_squares" : (sum_squares, ( -10.0,  10.0)),
    "dixon_price" : (dixon_price, ( -10.0,  10.0)),
    "zakharov"    : (zakharov,    (  -5.0,  10.0)),
    "rastrigin"   : (rastrigin,   (  -5.12, 5.12)),
    "ackley"      : (ackley,      ( -32.768,32.768)),
    "griewank"    : (griewank,    (-600.0, 600.0)),
    "schwefel"    : (schwefel,    (-500.0, 500.0)),
    "levy"        : (levy,        ( -10.0,  10.0)),
}

DIMENSOES   = [30, 50, 100]
N_EXECUCOES = 30
POP_SIZE    = 100
MAX_FES     = 100000 # Limite de chamadas de função (orçamento)


def rodar_experimento(algoritmo_nome: str, dry_run: bool = False) -> None:
    alg_fn   = ALGORITMOS[algoritmo_nome]
    n_exec   = 1 if dry_run else N_EXECUCOES

    out_dir  = Path("results")
    out_dir.mkdir(exist_ok=True)

    csv_resultados = out_dir / f"{algoritmo_nome}_resultados.csv"
    csv_historico  = out_dir / f"{algoritmo_nome}_historico.csv"

    combos = list(product(FUNCOES.items(), DIMENSOES))
    total  = len(combos) * n_exec

    print(f"\n{'='*60}")
    print(f"  Algoritmo : {algoritmo_nome.upper()}")
    print(f"  Funções   : {len(FUNCOES)}")
    print(f"  Dimensões : {DIMENSOES}")
    print(f"  Execuções : {n_exec}{'  (dry-run)' if dry_run else ''}")
    print(f"  Total     : {total} rodadas")
    print(f"  Chamadas de Funções : 100.000")
    print(f"{'='*60}\n")

    linhas_res  = []   # métricas resumidas
    linhas_hist = []   # curvas de convergência

    pbar = tqdm(total=total, unit="rodada", ncols=72)

    for (fn_nome, (fn, bounds)), dim in combos:
        
        for exec_id in range(n_exec):
            t0   = time.perf_counter()

            resultado = alg_fn(
                func     = fn,
                dim      = dim,
                bounds   = bounds,
                max_fes  = MAX_FES,
                pop_size = POP_SIZE,
            )

            elapsed = time.perf_counter() - t0

            # ── linha de métricas ─────────────────────────────────────────
            linhas_res.append({
                "algoritmo" : algoritmo_nome,
                "funcao"    : fn_nome,
                "dim"       : dim,
                "exec_id"   : exec_id + 1,
                "best_f"    : resultado["best_f"],
                "n_fes"     : resultado["n_fes"],
                "tempo_s"   : round(elapsed, 4),
            })

            # ── linhas do histórico ───────────────────────────────────────
            history     = resultado["history"]
            fes_history = resultado["fes_history"]

            for ponto, (fes_val, best_f_val) in enumerate(
                zip(fes_history, history), start=1
            ):
                linhas_hist.append({
                    "algoritmo" : algoritmo_nome,
                    "funcao"    : fn_nome,
                    "dim"       : dim,
                    "exec_id"   : exec_id + 1,
                    "geracao"   : ponto,
                    "n_fes"     : int(fes_val),
                    "best_f"    : float(best_f_val),
                })

            pbar.set_postfix_str(
                f"{fn_nome} D={dim} exec={exec_id+1} f*={resultado['best_f']:.3e}",
                refresh=False,
            )
            pbar.update(1)

    pbar.close()

    # ── salvar CSVs ───────────────────────────────────────────────────────────
    df_res  = pd.DataFrame(linhas_res)
    df_hist = pd.DataFrame(linhas_hist)

    df_res.to_csv(csv_resultados, index=False, float_format="%.10g")
    df_hist.to_csv(csv_historico, index=False, float_format="%.10g")

    # ── resumo no terminal ────────────────────────────────────────────────────
    print(f"\n✓ {csv_resultados}  ({len(df_res)} linhas)")
    print(f"✓ {csv_historico}   ({len(df_hist)} linhas)\n")

    print("── Resumo por função e dimensão ──────────────────────────────────")
    resumo = (
        df_res
        .groupby(["funcao", "dim"])["best_f"]
        .agg(media="mean", desvio="std", mediana="median", melhor="min")
        .round(6)
    )
    print(resumo.to_string())
    print()


# ── CLI ───────────────────────────────────────────────────────────────────────
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Pipeline experimental de metaheurísticas")
    parser.add_argument(
        "--algoritmo", choices=list(ALGORITMOS.keys()), default="ag",
        help="algoritmo a executar (padrão: ag)"
    )
    parser.add_argument(
        "--dry-run", action="store_true",
        help="executa apenas 1 rodada por combinação (teste rápido)"
    )
    args = parser.parse_args()
    rodar_experimento(args.algoritmo, dry_run=args.dry_run)