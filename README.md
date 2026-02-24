# Statistics Calculator (C, OCaml, Python)

This repository contains three implementations of a basic statistics calculator that computes:

- Mean
- Median
- Mode (supports multiple modes)

## Paradigms
- **C**: Procedural
- **OCaml**: Functional
- **Python**: Object-Oriented (class-based)

## Files
- `c/statistics.c`
- `ocaml/statistics.ml`
- `python/statistics_calculator.py`

## Example Input
`[4, 1, 2, 2, 3, 4, 5, 4, 2, 6, 7, 2, 4]`

## Expected Output (all implementations)
- Mean: `3.54`
- Median: `4.00`
- Mode(s): `2, 4` (frequency = 4)

## Run Instructions

### C
```bash
gcc c/statistics.c -o statistics
./statistics
```

### OCaml
```bash
ocaml ocaml/statistics.ml
```

### Python
```bash
python3 python/statistics_calculator.py
```
