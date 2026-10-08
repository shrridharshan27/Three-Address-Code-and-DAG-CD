# Three Address Code (TAC) & Directed Acyclic Graph (DAG) Optimization

[![Language](https://img.shields.io/badge/Language-C99%20%2F%20C11-00599C.svg?logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Compiler](https://img.shields.io/badge/Optimization-Common%20Subexpression%20Elimination-green.svg)](https://gcc.gnu.org/)
[![Course](https://img.shields.io/badge/Course-BCSE306L%20Compiler%20Design-red.svg)](https://vit.ac.in)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Author Information
- **Author:** Shrri Dharshan D R
- **GitHub:** [@shrridharshan27](https://github.com/shrridharshan27)
- **Registration Number:** `23BPS1090`
- **Course:** Compiler Design Laboratory (`BCSE306L`)
- **Lab Slot:** `L23+L24`

---

## Overview
This repository implements **Three Address Code (TAC)** generation and **Directed Acyclic Graph (DAG)** construction for intermediate representation optimization. A DAG represents arithmetic expressions with shared subtrees, enabling **Common Subexpression Elimination (CSE)** prior to machine code synthesis.

---

## Benchmark Expressions
1. $x = (a + b) * (c - d) + (e * f) - (a + b)$
2. $y = ((p + q) * r) + ((p + q) * s) + (r * s)$
3. $z = (a * b + c * d) * (e + f) + (a * b)$
4. $res = ((a + b) * (c + d)) + ((a + b) * (c + d)) + ((e + f) * (g - h))$

---

## Compilation & Execution
```bash
# Compile and run with GCC
gcc -std=c99 -Wall -Wextra src/tac_and_dag.c -o build/tac_dag
./build/tac_dag
```

---

## License
MIT License - see [LICENSE](LICENSE) for details.
