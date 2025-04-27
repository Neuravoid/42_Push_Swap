
# push_swap

Welcome to **push_swap**, a project developed as part of the 42 curriculum.  
The goal of this project is to sort a list of integers using two stacks (**A** and **B**) with a limited set of operations, using the fewest possible moves.

## Project Overview

- Input: A list of integers.
- Goal: Sort the list in ascending order using predefined stack operations:
  - `sa` / `sb` / `ss` — Swap the top two elements of stack A, B, or both.
  - `pa` / `pb` — Push the top element from one stack to the other.
  - `ra` / `rb` / `rr` — Rotate stack A, B, or both upwards.
  - `rra` / `rrb` / `rrr` — Rotate stack A, B, or both downwards.

The fewer the moves, the better!

## Features

- Input parsing and validation (including duplicate and non-integer detection).
- Dynamic stack management using linked lists.
- Optimized sorting algorithm:
  - Specific small-stack algorithms (e.g., 2–5 elements).
  - Efficient chunking method for larger stacks.
- Memory management:
  - Proper `malloc` and `free` usage to avoid memory leaks.
- Norm-compliant and efficient code.

## Installation

### Requirements
- Unix-based OS (Linux / macOS)
- `gcc` compiler
- `make`

### Clone the repository
```bash
git clone https://github.com/Neuravoid/42_Push_Swap.git
cd push_swap
```

### Compile
```bash
make
```

This will produce the `push_swap` executable.

## Usage

```bash
./push_swap [list of integers]
```

Example:
```bash
./push_swap 3 2 1 6 5 8
```

The program will output a list of operations needed to sort the stack.

You can test the number of operations using:

```bash
ARG="3 2 1 6 5 8"; ./push_swap $ARG | wc -l
```

Or check the correctness using your own checker script.

## Notes

- Efficient for very small numbers of elements (under 5).
- Advanced strategies applied for larger input sizes (chunking, greedy algorithm).
- Proper error management (non-numeric input, integer overflows, duplicates).
- No memory leaks (validated with `valgrind`).

## License

This project is part of the 42 School curriculum and follows its academic honesty policy.
