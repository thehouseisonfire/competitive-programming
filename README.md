<div align="center">

# Competitive Marathon

**Programming marathon problems and solutions** — Beecrowd, Codeforces, Atcoder and friends.

![Language](https://img.shields.io/badge/language-C%2B%2B-blue)
![License](https://img.shields.io/badge/license-MIT%20%7C%20Apache--2.0-brightgreen)

</div>

---

## Repository structure

Everything is organized in the same way for every online judge:

```
Online Judge
└── Contest (number, name or date — *if* any)
    └── Problem (letter, number or name)
```

### Example

```
OBI/
└── 2015-F1/                       # contest = year & phase
    └── Metro/                     # problem = Metro
        ├── metro.cpp              # solution
        ├── metro.in               # sample input
        └── metro.in2              # extra test input
```

The judges currently covered:

| Judge | Folder | Contest folder | Problem folder |
|---|---|---|---|
| OBI (Olímpiada Brasileira de Informática) | `OBI/` | year & phase (e.g. `2015-F1`) | problem name (e.g. `Metro`) |
| Beecrowd | `Beecrowd/` | — | problem number (e.g. `1001`) |
| Codeforces | `Codeforces/` | round id (e.g. `158`) | letter + name (e.g. `A-Next-Round`) |
| Atcoder | `Atcoder/` | contest id (e.g. `DP`) | problem name (e.g. `Coins`) |
| CSES | `CSES/` | — | problem name (e.g. `Book-Shop`) |
| CodeChef | `CodeChef/` | — | problem code (e.g. `TALCA`) |
| V-Judge | `V-Judge/` | week (e.g. `W1`) | problem letter (e.g. `A`) |
| LeetCode | `LeetCode/` | — | number + name (e.g. `496-Next-Greater-Element-I`) |
| SPOJ | `SPOJ/` | — | problem code (e.g. `FARIDA`) |
| Misc | `Misc/` | — | problem name (e.g. `Karamell`) |

### Special folders

| Folder | Description |
|---|---|
| `2026-regionals/` | Regional contest problems from 2026 |
| `MOJ-Esquenta-2026/` | MOJ Esquenta 2026 contest problems |

## Running the solutions

```bash
g++ -O2 -std=c++17 OBI/2015-F1/Metro/metro.cpp -o metro
./metro < OBI/2015-F1/Metro/metro.in
```

## Conventions

- Solutions are written in C++ (anything from C++11 to C++23).
- Each problem folder may include test inputs (`*.in`) and, if needed, a short note on the approach.
- `Misc/` holds problems whose judge could not be identified.

Problem statements belong to their respective judges/olympids.
