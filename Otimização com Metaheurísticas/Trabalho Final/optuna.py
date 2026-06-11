"""
optuna.py
=========
Otimização de hiperparâmetros para metaheurísticas usando Optuna.
    
Uso
---
    python optuna.py --algoritmo ag                     # otimizar AG em todas as 10 funções
    python optuna.py --algoritmo de                     # otimizar DE
    python optuna.py --algoritmo pso                    # otimizar PSO
    python optuna.py --algoritmo epso                   # otimizar EPSO
    python optuna.py --algoritmo ag --funcao sphere     # otimizar AG apenas em Sphere

Estrutura de saída
------------------
hparams/
  ag_hparams.json      ← melhores hiperparâmetros por função
  de_hparams.json
  pso_hparams.json
    epso_hparams.json

  ag_estudo_sphere.pkl ← estudo Optuna completo (visualizar com Optuna)
  ...
"""

import argparse
import json
import pickle
import sys
import importlib
from pathlib import Path
from typing import Any, Dict, Tuple

import numpy as np
import pandas as pd

# Evita conflito entre este arquivo (optuna.py) e o pacote externo optuna.
_THIS_DIR = Path(__file__).resolve().parent
_ORIGINAL_SYS_PATH = list(sys.path)
try:
    sys.path = [p for p in sys.path if Path(p or ".").resolve() != _THIS_DIR]
    optuna = importlib.import_module("optuna")
finally:
    sys.path = _ORIGINAL_SYS_PATH

from optuna.samplers import TPESampler
from optuna.pruners import MedianPruner

# ── benchmark ─────────────────────────────────────────────────────────────
from benchmark import (
    sphere, rosenbrock, sum_squares, dixon_price, zakharov,
    rastrigin, ackley, griewank, schwefel, levy,
)

# ── algoritmos ────────────────────────────────────────────────────────────
from ag import ag
from de import de
from epso import epso
from pso import pso


FUNCOES = {
    "sphere": (sphere, (-100.0, 100.0)),
    "rosenbrock": (rosenbrock, (-5.0, 10.0)),
    "sum_squares": (sum_squares, (-10.0, 10.0)),
    "dixon_price": (dixon_price, (-10.0, 10.0)),
    "zakharov": (zakharov, (-5.0, 10.0)),
    "rastrigin": (rastrigin, (-5.12, 5.12)),
    "ackley": (ackley, (-32.768, 32.768)),
    "griewank": (griewank, (-600.0, 600.0)),
    "schwefel": (schwefel, (-500.0, 500.0)),
    "levy": (levy, (-10.0, 10.0)),
}

# ── configuração experimental ─────────────────────────────────────────────
DIMENSAO = [30, 50, 100]  # testar em 3 dimensões: 30, 50 e 100
MAX_FES = 100000  # orçamento = 100.000
POP_SIZE = 100
N_TRIALS = 101  # número de tentativas por função


# ── Objetivos de otimização ───────────────────────────────────────────────

def objetivo_ag(trial: Any, func_nome: str, dim: int) -> float:
    """Objetivo para otimizar AG em uma função específica e dimensão."""
    func, bounds = FUNCOES[func_nome]

    # sugerir hiperparâmetros
    taxa_mutacao = trial.suggest_float("taxa_mutacao", 0.01, 0.2)
    sigma_mutacao = trial.suggest_float("sigma_mutacao", 0.05, 0.5)
    alpha_blx = trial.suggest_float("alpha_blx", 0.1, 0.5)

    # executar AG
    resultado = ag(
        func=func,
        dim=dim,
        bounds=bounds,
        max_fes=MAX_FES,
        pop_size=POP_SIZE,
        seed=42,
        taxa_mutacao=taxa_mutacao,
        sigma_mutacao=sigma_mutacao,
        alpha_blx=alpha_blx,
    )

    # relatório intermediário para poda
    trial.report(resultado["best_f"], 0)

    if trial.should_prune():
        raise optuna.TrialPruned()

    return resultado["best_f"]


def objetivo_de(trial: Any, func_nome: str, dim: int) -> float:
    """Objetivo para otimizar DE em uma função específica e dimensão."""
    func, bounds = FUNCOES[func_nome]

    # sugerir hiperparâmetros
    F = trial.suggest_float("F", 0.4, 1.5)
    CR = trial.suggest_float("CR", 0.1, 1.0)

    # executar DE
    resultado = de(
        func=func,
        dim=dim,
        bounds=bounds,
        max_fes=MAX_FES,
        pop_size=POP_SIZE,
        seed=42,
        F=F,
        CR=CR,
    )

    trial.report(resultado["best_f"], 0)

    if trial.should_prune():
        raise optuna.TrialPruned()

    return resultado["best_f"]


def objetivo_pso(trial: Any, func_nome: str, dim: int) -> float:
    """Objetivo para otimizar PSO em uma função específica e dimensão."""
    func, bounds = FUNCOES[func_nome]

    # sugerir hiperparâmetros
    w = trial.suggest_float("w", 0.3, 1.0)
    c1 = trial.suggest_float("c1", 0.5, 2.5)
    c2 = trial.suggest_float("c2", 0.5, 2.5)

    # executar PSO
    resultado = pso(
        func=func,
        dim=dim,
        bounds=bounds,
        max_fes=MAX_FES,
        pop_size=POP_SIZE,
        seed=42,
        w=w,
        c1=c1,
        c2=c2,
    )

    trial.report(resultado["best_f"], 0)

    if trial.should_prune():
        raise optuna.TrialPruned()

    return resultado["best_f"]


def objetivo_epso(trial: Any, func_nome: str, dim: int) -> float:
    """Objetivo para otimizar EPSO em uma função específica e dimensão."""
    func, bounds = FUNCOES[func_nome]

    # sugerir hiperparâmetros
    comm_prob = trial.suggest_float("comm_prob", 0.1, 0.9)
    tau = trial.suggest_float("tau", 0.05, 0.5)

    # executar EPSO
    resultado = epso(
        func=func,
        dim=dim,
        bounds=bounds,
        max_fes=MAX_FES,
        pop_size=POP_SIZE,
        seed=42,
        comm_prob=comm_prob,
        tau=tau,
    )

    trial.report(resultado["best_f"], 0)

    if trial.should_prune():
        raise optuna.TrialPruned()

    return resultado["best_f"]

# ── Pipeline de otimização ────────────────────────────────────────────────

def otimizar_algoritmo(
    algoritmo_nome: str,
    funcoes_lista: list = None,
) -> Dict[str, Dict]:
    """
    Otimiza hiperparâmetros de um algoritmo em várias funções.

    Parâmetros
    ----------
    algoritmo_nome : str
        Nome do algoritmo ('ag', 'de', 'pso')
    funcoes_lista : list, optional
        Lista de nomes de funções. Se None, otimiza em todas.

    Retorna
    -------
    dict
        Melhores hiperparâmetros por função
    """
    if funcoes_lista is None:
        funcoes_lista = list(FUNCOES.keys())

    # escolher função objetivo
    objetivo_map = {
        "ag": objetivo_ag,
        "de": objetivo_de,
        "epso": objetivo_epso,
        "pso": objetivo_pso,
    }

    if algoritmo_nome not in objetivo_map:
        raise ValueError(
            f"Algoritmo '{algoritmo_nome}' desconhecido. "
            f"Opções: {list(objetivo_map.keys())}"
        )

    objetivo_fn = objetivo_map[algoritmo_nome]
    hparams_por_funcao = {}

    out_dir = Path("hparams")
    out_dir.mkdir(exist_ok=True)

    print(f"\n{'='*70}")
    print(f"  Otimizando hiperparâmetros para {algoritmo_nome.upper()}")
    print(f"  Dimensões: {DIMENSAO}")
    print(f"  Orçamento (max_fes): {MAX_FES}")
    print(f"  Tamanho da população: {POP_SIZE}")
    print(f"  Trials por função/dimensão: {N_TRIALS}")
    print(f"{'='*70}\n")

    for func_nome in funcoes_lista:
        for dim in DIMENSAO:
            print(f"▶ Otimizando em função: {func_nome} | dimensão: {dim}")

            # criar sampler e pruner
            sampler = TPESampler(seed=42)
            pruner = MedianPruner()

            # criar estudo
            estudo = optuna.create_study(
                direction="minimize",
                sampler=sampler,
                pruner=pruner,
            )

            # otimizar
            estudo.optimize(
                lambda trial: objetivo_fn(trial, func_nome, dim),
                n_trials=N_TRIALS,
                show_progress_bar=True,
            )

            # salvar estudo
            estudo_path = out_dir / f"{algoritmo_nome}_estudo_{func_nome}_d{dim}.pkl"
            with open(estudo_path, "wb") as f:
                pickle.dump(estudo, f)

            # melhor trial
            trial_otimo = estudo.best_trial
            hparams_por_funcao.setdefault(func_nome, {})[str(dim)] = {
                "best_value": float(trial_otimo.value),
                "hparams": trial_otimo.params,
                "trial_number": trial_otimo.number,
            }

            print(
                f"  ✓ Melhor f* = {trial_otimo.value:.6e} "
                f"(trial #{trial_otimo.number})"
            )
            print(f"  ✓ Hiperparâmetros: {trial_otimo.params}\n")

    # salvar hiperparâmetros em JSON
    hparams_path = out_dir / f"{algoritmo_nome}_hparams.json"
    with open(hparams_path, "w") as f:
        json.dump(hparams_por_funcao, f, indent=2)

    print(f"\n✓ Hiperparâmetros salvos em: {hparams_path}")

    # gerar resumo em CSV
    resumo_data = []
    for func_nome, dims_info in hparams_por_funcao.items():
        for dim_str, info in dims_info.items():
            row = {"funcao": func_nome, "dim": int(dim_str), "best_f": info["best_value"]}
            row.update(info["hparams"])
            resumo_data.append(row)

    df_resumo = pd.DataFrame(resumo_data)
    resumo_path = out_dir / f"{algoritmo_nome}_resumo.csv"
    df_resumo.to_csv(resumo_path, index=False)

    print(f"✓ Resumo salvo em: {resumo_path}\n")

    # resumo visual
    print("── Resumo de Resultados ──────────────────────────────────────")
    if not df_resumo.empty:
        print(df_resumo.sort_values(["funcao", "dim"]).to_string(index=False))
    else:
        print("(nenhum resultado)")
    print()

    return hparams_por_funcao


# ── CLI ───────────────────────────────────────────────────────────────────

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Otimização de hiperparâmetros para metaheurísticas"
    )
    parser.add_argument(
        "--algoritmo",
        choices=["ag", "de", "epso", "pso"],
        required=True,
        help="algoritmo a otimizar",
    )
    parser.add_argument(
        "--funcao",
        default=None,
        help="função específica para otimizar (padrão: todas)",
    )
    parser.add_argument(
        "--trials",
        type=int,
        default=N_TRIALS,
        help=f"número de trials por função (padrão: {N_TRIALS})",
    )

    args = parser.parse_args()

    # ajustar número de trials
    N_TRIALS = args.trials

    # determinar lista de funções
    funcoes = None
    if args.funcao:
        if args.funcao not in FUNCOES:
            print(f"❌ Função '{args.funcao}' desconhecida.")
            print(f"   Opções: {list(FUNCOES.keys())}")
            exit(1)
        funcoes = [args.funcao]

    # otimizar
    hparams = otimizar_algoritmo(args.algoritmo, funcoes)
