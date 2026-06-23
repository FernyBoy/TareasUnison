import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import os

CSV_DIR = "csv"
GRAPH_DIR = "graphs"
os.makedirs(GRAPH_DIR, exist_ok=True)

ALGO_META = {
    "Polinomio1": {"title": "Polinomio 1 — Potencia con ciclo anidado", "complejidad": r"$O(n^2)$",  "color": "#2563EB"},
    "Polinomio2": {"title": "Polinomio 2 — Potencia recursiva",          "complejidad": r"$O(n \log n)$", "color": "#7C3AED"},
    "Polinomio3": {"title": "Polinomio 3 — Multiplicación acumulada",    "complejidad": r"$O(n)$",    "color": "#059669"},
    "Polinomio4": {"title": "Polinomio 4 — Regla de Horner",             "complejidad": r"$O(n)$",    "color": "#D97706"},
    "Sum":        {"title": "Sum — Suma iterativa",                       "complejidad": r"$O(n)$",    "color": "#059669"},
    "RSum":       {"title": "RSum — Suma recursiva",                      "complejidad": r"$O(n)$",    "color": "#7C3AED"},
    "Add":        {"title": "Add — Suma de matrices $n \\times n$",       "complejidad": r"$O(n^2)$",  "color": "#2563EB"},
    "Trasp":      {"title": "Trasp — Transpuesta de matriz $n \\times n$","complejidad": r"$O(n^2)$",  "color": "#DC2626"},
    "Mult":       {"title": "Mult — Multiplicación de matrices",          "complejidad": r"$O(n^3)$",  "color": "#D97706"},
    "Perm":       {"title": "Perm — Permutaciones",                       "complejidad": r"$O(n!)$",   "color": "#DC2626"},
    "SeqSearch":  {"title": "SeqSearch — Búsqueda secuencial centinela",  "complejidad": r"$O(n)$",    "color": "#059669"},
}

def fmt_ns(ns):
    """Devuelve etiqueta legible para el eje Y."""
    if ns >= 1e9:   return f"{ns/1e9:.2f} s"
    if ns >= 1e6:   return f"{ns/1e6:.2f} ms"
    if ns >= 1e3:   return f"{ns/1e3:.2f} µs"
    return f"{ns:.0f} ns"

def best_unit(max_ns):
    if max_ns >= 1e9:   return 1e9,  "Tiempo (segundos)"
    if max_ns >= 1e6:   return 1e6,  "Tiempo (milisegundos)"
    if max_ns >= 1e3:   return 1e3,  "Tiempo (microsegundos)"
    return 1.0, "Tiempo (nanosegundos)"

for algo, meta in ALGO_META.items():
    csv_path = os.path.join(CSV_DIR, f"{algo}.csv")
    if not os.path.exists(csv_path):
        print(f"[OMITIDO] {csv_path} no encontrado")
        continue

    df = pd.read_csv(csv_path)
    n   = df["n"].values
    t   = df["time_ns"].values

    divisor, ylabel = best_unit(t.max())
    t_scaled = t / divisor

    fig, ax = plt.subplots(figsize=(8, 5))

    ax.plot(n, t_scaled,
            color=meta["color"], linewidth=2.2,
            marker="o", markersize=6, markerfacecolor="white",
            markeredgewidth=2, markeredgecolor=meta["color"],
            zorder=3)

    ax.fill_between(n, t_scaled, alpha=0.08, color=meta["color"])

    ax.set_title(meta["title"], fontsize=13, fontweight="bold", pad=12)
    ax.set_xlabel("n", fontsize=11)
    ax.set_ylabel(ylabel, fontsize=11)

    # Anotación de complejidad
    ax.text(0.97, 0.05, meta["complejidad"],
            transform=ax.transAxes,
            fontsize=13, ha="right", va="bottom",
            color=meta["color"],
            bbox=dict(boxstyle="round,pad=0.3",
                      facecolor="white", edgecolor=meta["color"], alpha=0.8))

    ax.grid(True, linestyle="--", linewidth=0.5, alpha=0.5)
    ax.set_xlim(left=0)
    ax.set_ylim(bottom=0)
    ax.xaxis.set_major_formatter(ticker.FuncFormatter(
        lambda x, _: f"{int(x):,}".replace(",", "_") if x >= 1000 else str(int(x))
    ))

    fig.tight_layout()
    out = os.path.join(GRAPH_DIR, f"{algo}.png")
    fig.savefig(out, dpi=150, bbox_inches="tight")
    plt.close(fig)
    print(f"[OK] {out}")

print("\nGráficas generadas en:", GRAPH_DIR)
