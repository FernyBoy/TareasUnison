import pandas as pd
import os

CSV_DIR = "csv"

ALGO_META = {
    "Polinomio1": ("Polinomio 1",  r"$O(n^2)$"),
    "Polinomio2": ("Polinomio 2",  r"$O(n \log n)$"),
    "Polinomio3": ("Polinomio 3",  r"$O(n)$"),
    "Polinomio4": ("Polinomio 4",  r"$O(n)$"),
    "Sum":        ("Sum",           r"$O(n)$"),
    "RSum":       ("RSum",          r"$O(n)$"),
    "Add":        ("Add",           r"$O(n^2)$"),
    "Trasp":      ("Trasp",         r"$O(n^2)$"),
    "Mult":       ("Mult",          r"$O(n^3)$"),
    "Perm":       ("Perm",          r"$O(n!)$"),
    "SeqSearch":  ("SeqSearch",     r"$O(n)$"),
}

def fmt_time(ns):
    """Formato legible: auto-escala a ns / µs / ms / s."""
    if ns >= 1_000_000_000:
        return f"{ns/1e9:.4f}\\,s"
    if ns >= 1_000_000:
        return f"{ns/1e6:.4f}\\,ms"
    if ns >= 1_000:
        return f"{ns/1e3:.4f}\\,µs"
    return f"{ns:.0f}\\,ns"

def fmt_n(n):
    """Formato con separador de miles usando coma."""
    return f"{n:,}"

lines = []
lines.append(r"\documentclass{article}")
lines.append(r"\usepackage[utf8]{inputenc}")
lines.append(r"\usepackage{booktabs}")
lines.append(r"\usepackage{amsmath}")
lines.append(r"\usepackage[margin=2cm]{geometry}")
lines.append(r"\begin{document}")
lines.append(r"")

for algo, (nombre, complejidad) in ALGO_META.items():
    csv_path = os.path.join(CSV_DIR, f"{algo}.csv")
    if not os.path.exists(csv_path):
        print(f"[OMITIDO] {csv_path} no encontrado")
        continue

    df = pd.read_csv(csv_path)

    lines.append(r"\begin{table}[ht]")
    lines.append(r"  \centering")
    lines.append(f"  \\caption{{Tiempos de ejecución — {nombre} ({complejidad})}}")
    lines.append(f"  \\label{{tab:{algo.lower()}}}")
    lines.append(r"  \begin{tabular}{rr}")
    lines.append(r"    \toprule")
    lines.append(r"    $n$ & Tiempo de ejecución \\")
    lines.append(r"    \midrule")

    for _, row in df.iterrows():
        n_str = fmt_n(int(row["n"]))
        t_str = fmt_time(row["time_ns"])
        lines.append(f"    {n_str} & {t_str} \\\\")

    lines.append(r"    \bottomrule")
    lines.append(r"  \end{tabular}")
    lines.append(r"\end{table}")
    lines.append(r"")

lines.append(r"\end{document}")

out_path = "tablas.tex"
with open(out_path, "w", encoding="utf-8") as f:
    f.write("\n".join(lines))

print(f"[OK] {out_path} generado")
