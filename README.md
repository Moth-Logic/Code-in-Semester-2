# homework-s2

[![Python 3.x](https://img.shields.io/badge/Python-3.x-3776AB?logo=python&logoColor=white)](https://www.python.org/)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Comments in Spanish](https://img.shields.io/badge/comments-espa%C3%B1ol-yellow)](#notes)
[![License: Unlicense](https://img.shields.io/badge/license-Unlicense-blue)](LICENSE)
[![Status](https://img.shields.io/badge/status-coursework-lightgrey)](#)

Homework and practice from my second semester of CS. The repo is in English, but
the code, comments and variable names are in Spanish because that is how it gets
submitted in class.

These are small, direct scripts meant to practice the basics of programming
(conditionals, loops, functions, formulas) rather than to solve hard problems.
No dependencies, no frameworks, no setup: every file runs on its own. The
assignment is written twice, in Python and in C++, with the same functions and
the same logic.

## Contents

| Path | What's there |
| --- | --- |
| `FirstPY_homework/1stPY_HW.py` | Second assignment in Python: 21 exercises, one function each |
| `FirstPY_homework_cpp/1stPY_HW.cpp` | The same 21 exercises in C++17 |
| `FirstPY_homework/IMPORTANT_NOTES.md` | Context for the assignment and the odd/even split |
| `LICENSE` | Unlicense (public domain) |

## Running

### Python

Needs Python 3.8+; there is nothing to install.

```bash
python FirstPY_homework/1stPY_HW.py
```

That prints a short sample of results. To use the functions from another script,
import them with `importlib`, because the filename starts with a digit and can't
be written with normal `import` syntax:

```python
import importlib

hw = importlib.import_module('FirstPY_homework.1stPY_HW')
print(hw.circulo(2))
```

The `if __name__ == '__main__'` block at the bottom keeps the file quiet when
imported.

### C++

Needs a C++17 compiler (tested with g++ 16 on Windows/MSYS2); only the standard
library is used.

```bash
g++ -std=c++17 -Wall -Wextra -pedantic FirstPY_homework_cpp/1stPY_HW.cpp -o 1stPY_HW
./1stPY_HW        # on Windows: 1stPY_HW.exe
```

It prints the same sample of results as the Python version.

## Exercises

Odd-numbered exercises are the ones submitted for class; even ones I solved on
my own. Each function documents what it takes, what it returns, the approach used
and its assumptions. Both languages implement the same 21 functions; the C++
version maps Python's dicts to structs (`ResultadoCirculo`, `AreaVolumen`,
`Aumento`), tuples to `std::array` and `None` to `std::optional`.

| # | Function | What it does |
| --- | --- | --- |
| 1 | `circulo` | Area and circumference of a circle |
| 2 | `numLetras` | Spells a single digit (0-9) in words |
| 3 | `esfera` | Surface area and volume of a sphere |
| 4 | `foo` | Divides a number by 7 (nested-call example) |
| 5 | `bisiesto` | Leap-year check |
| 6 | `desglose` | Breaks an amount into bills and coins |
| 7 | `mediano` | Middle value of three numbers |
| 8 | `orden` | Sorts three numbers from largest to smallest |
| 9 | `disco` | Converts GB to bytes |
| 10 | `misterio` | Lambda and scope exercise |
| 11 | `convertir` | Meters to cm, inches, feet or yards |
| 12 | `calcSalario` | Weekly pay with overtime |
| 13 | `aumento` | Salary raise by bracket |
| 14 | `faltante` | Minutes left until midnight |
| 15 | `palindromo` | Numeric palindrome check |
| 16 | `significativo` | Hundreds digit of a 3-digit number |
| 17 | `adjunto` | Appends a digit to the right of a number |
| 18 | `interesCompuesto` | Compound interest |
| 19 | `toro` | Area and volume of a torus |
| 20 | `invertir` | Reverses the digits of a number |
| 21 | `numLetras2` | Spells a whole number digit by digit, hyphen-separated |

`length` and `invertir` live in an internal-utilities section instead of their own
exercise blocks: `length` supports #21, and `invertir` answers #20 while also
being reused by #15 and #21.

## Notes

- **Language:** README in English, code and comments in Spanish.
- **Scope:** intro-course exercises; no tests and no keyboard input, every
  function receives its data as arguments.
- **Two languages:** the Python script and the C++ port share section order,
  function names and documented behavior, so they can be read side by side.

## Tags

`python` · `cpp` · `homework` · `university` · `beginner-friendly` · `exercises` ·
`algorithms` · `spanish` · `unlicense`

## License

Public domain under the [Unlicense](LICENSE).
