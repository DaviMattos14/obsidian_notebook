import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
from matplotlib import colormaps
from matplotlib.colors import LogNorm

# ── Importa as funções de benchmark ──────────────────────────────────────────
import sys, os
sys.path.insert(0, os.path.dirname(__file__))
from benchmark import (
    sphere, rosenbrock, sum_squares, dixon_price, zakharov,
    ackley, rastrigin, griewank, schwefel, levy,
)

# ── Configuração de cada função ───────────────────────────────────────────────
FUNCTIONS = [
    # (nome,        callable,    domínio,     use_log, tipo)
    ("Sphere",      sphere,      (-5,   5),   False,  "Unimodal"),
    ("Rosenbrock",  rosenbrock,  (-2,   2),   False,  "Unimodal"),
    ("Sum Squares", sum_squares, (-5,   5),   False,  "Unimodal"),
    ("Dixon-Price", dixon_price, (-3,   3),   False,  "Unimodal"),
    ("Zakharov",    zakharov,    (-5,   5),   False,  "Unimodal"),
    ("Rastrigin",   rastrigin,   (-5.12,5.12),False,  "Multimodal"),
    ("Ackley",      ackley,      (-5,   5),   False,  "Multimodal"),
    ("Griewank",    griewank,    (-10,  10),  False,  "Multimodal"),
    ("Schwefel",    schwefel,    (-500, 500), False,  "Multimodal"),
    ("Levy",        levy,        (-5,   5),   False,  "Multimodal"),
]

RESOLUTION = 400   # pontos por eixo na grade
N_CONTOURS = 25    # linhas de nível

CMAP_SURF    = "viridis"
CMAP_CONTOUR = "viridis"

UNIMODAL_COLOR   = "#185FA5"   # azul
MULTIMODAL_COLOR = "#993C1D"   # coral


# ── Helpers ───────────────────────────────────────────────────────────────────
def make_grid(fn, lo, hi, n=RESOLUTION):
    """Cria malha 2-D e avalia a função de forma vetorizada."""
    x = np.linspace(lo, hi, n)
    y = np.linspace(lo, hi, n)
    X, Y = np.meshgrid(x, y)
    XY = np.column_stack([X.ravel(), Y.ravel()])
    Z = fn(XY).reshape(n, n)
    return X, Y, Z


def safe_norm(Z):
    """Normalização log-safe: retorna norm=None se Z for totalmente não-positivo."""
    Zmin = Z.min()
    if Zmin < 0:
        return None               # não aplica log com valores negativos
    if Zmin == 0:
        Zp = Z + 1e-10            # evita log(0)
    else:
        Zp = Z
    if Zp.max() / Zp.min() > 100:
        return LogNorm(vmin=Zp.min(), vmax=Zp.max())
    return None


# ── Layout: 10 funções × 2 painéis (3-D + contorno) ─────────────────────────
fig = plt.figure(figsize=(22, 44))
fig.patch.set_facecolor("#ffffff")

# Grade: 10 linhas × 2 colunas, com separação extra entre unimodais e multimodais
outer = gridspec.GridSpec(
    10, 2,
    figure=fig,
    hspace=0.35,
    wspace=0.08,
    left=0.04, right=0.96,
    top=0.97,  bottom=0.02,
)

for idx, (name, fn, (lo, hi), use_log, tipo) in enumerate(FUNCTIONS):

    ax3d  = fig.add_subplot(outer[idx, 0], projection="3d")
    ax2d  = fig.add_subplot(outer[idx, 1])

    accent = UNIMODAL_COLOR if tipo == "Unimodal" else MULTIMODAL_COLOR

    # ── Dados ────────────────────────────────────────────────────────────────
    X, Y, Z = make_grid(fn, lo, hi)
    norm = safe_norm(Z) if use_log else None

    # ── Superfície 3-D ───────────────────────────────────────────────────────
    ax3d.set_facecolor("#0f0f0f")
    surf = ax3d.plot_surface(
        X, Y, Z,
        cmap=CMAP_SURF,
        norm=norm,
        linewidth=0,
        antialiased=True,
        alpha=0.92,
        rcount=120, ccount=120,
    )

    # Projeção das curvas de nível no plano z-mínimo
    zfloor = Z.min() - 0.05 * (Z.max() - Z.min())
    ax3d.contourf(
        X, Y, Z,
        zdir="z", offset=zfloor,
        levels=N_CONTOURS,
        cmap=CMAP_CONTOUR,
        alpha=0.55,
        norm=norm,
    )

    ax3d.set_zlim(zfloor, Z.max())
    ax3d.set_xlabel("x₁", color="#aaaaaa", fontsize=8, labelpad=2)
    ax3d.set_ylabel("x₂", color="#aaaaaa", fontsize=8, labelpad=2)
    ax3d.set_zlabel("f(x)", color="#aaaaaa", fontsize=8, labelpad=2)
    ax3d.tick_params(colors="#666666", labelsize=6, pad=1)
    for pane in [ax3d.xaxis.pane, ax3d.yaxis.pane, ax3d.zaxis.pane]:
        pane.fill = False
        pane.set_edgecolor("#222222")
    ax3d.grid(True, color="#222222", linewidth=0.4)
    ax3d.view_init(elev=28, azim=-50)

    # Título da linha (sobre o painel 3-D)
    badge = "UNIMODAL" if tipo == "Unimodal" else "MULTIMODAL"
    ax3d.set_title(
        f"{name}",
        color="white", fontsize=13, fontweight="bold",
        loc="left", pad=8,
    )

    # ── Curvas de nível 2-D ──────────────────────────────────────────────────
    ax2d.set_facecolor("#0f0f0f")

    cf = ax2d.contourf(
        X, Y, Z,
        levels=N_CONTOURS,
        cmap=CMAP_CONTOUR,
        norm=norm,
        alpha=0.9,
    )
    ax2d.contour(
        X, Y, Z,
        levels=N_CONTOURS,
        colors="white",
        linewidths=0.3,
        alpha=0.35,
        norm=norm,
    )

    # Colorbar compacta
    cbar = fig.colorbar(cf, ax=ax2d, fraction=0.046, pad=0.04)
    cbar.ax.tick_params(labelsize=6, colors="#888888")
    cbar.outline.set_edgecolor("#333333")

    # Marca o ótimo em (0,0) para todas exceto Schwefel e Rosenbrock
    if name == "Schwefel":
        opt = (420.9687, 420.9687)
    elif name == "Rosenbrock":
        opt = (1.0, 1.0)
    elif name == "Dixon-Price":
        opt = (1.0, 1.0 / np.sqrt(2))
    else:
        opt = (0.0, 0.0)

    ax2d.plot(
        *opt, marker="*", markersize=10,
        color="white", markeredgecolor=accent,
        markeredgewidth=1.2, zorder=5,
        clip_on=True,
    )

    ax2d.set_xlim(lo, hi)
    ax2d.set_ylim(lo, hi)
    ax2d.set_xlabel("x₁", color="#aaaaaa", fontsize=8)
    ax2d.set_ylabel("x₂", color="#aaaaaa", fontsize=8)
    ax2d.tick_params(colors="#666666", labelsize=6)
    for sp in ax2d.spines.values():
        sp.set_edgecolor("#333333")

    # Badge tipo no canto do contorno
    ax2d.text(
        0.97, 0.97, badge,
        transform=ax2d.transAxes,
        ha="right", va="top",
        fontsize=7, fontweight="bold",
        color=accent,
        bbox=dict(
            boxstyle="round,pad=0.3",
            facecolor="#0f0f0f",
            edgecolor=accent,
            linewidth=0.8,
            alpha=0.85,
        ),
    )

    ax2d.set_title(
        "curvas de nível  ★ = ótimo global",
        color="#888888", fontsize=8, loc="right", pad=6,
    )

# ── Título geral ──────────────────────────────────────────────────────────────
fig.text(
    0.5, 0.985,
    "Funções de Benchmark — Superfície 3D e Curvas de Nível (2D)",
    ha="center", va="top",
    color="white", fontsize=16, fontweight="bold",
)
fig.text(
    0.5, 0.979,
    "esquerda: superfície f(x₁, x₂)  ·  direita: curvas de nível + ótimo global (★)",
    ha="center", va="top",
    color="#666666", fontsize=9,
)

# ── Salva ─────────────────────────────────────────────────────────────────────
out_path = os.path.join(os.path.dirname(__file__), "benchmark_plots.png")
fig.savefig(
    out_path,
    dpi=150,
    bbox_inches="tight",
    facecolor=fig.get_facecolor(),
)
print(f"Salvo em: {out_path}")
plt.close(fig)