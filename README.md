
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
  - Specific small-stack algorithms (e.g., 2-3-4 elements).
  - Turkish algorithm for larger stacks.
- Bonus: 
  - **checker** program implemented.
  - Reads operations from `stdin` using a custom-made `get_next_line`.
  - Verifies if the sequence of operations correctly sorts the list.
  - Handles memory management carefully, ensuring no leaks even in error cases.
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
cd 42_Push_Swap
```

### Compile
```bash
make
```

This will produce the `push_swap` and `checker` executables.

## Usage

### push_swap
```bash
./push_swap [list of integers]
```

Example:
```bash
./push_swap 3 2 1 6 5 8
```
The program will output a list of operations needed to sort the stack.

### checker
```bash
./checker [list of integers]
```

You can manually input a sequence of operations (one per line), and when done, checker will output `OK` if sorted or `KO` if not.

Example:
```bash
ARG="2 1 3"; ./checker $ARG
sa
(CTRL+D)
```

Alternatively, you can pipe instructions:
```bash
ARG="2 1 3"; ./push_swap $ARG | ./checker $ARG
```

### Test the number of moves
```bash
ARG="3 2 1 6 5 8"; ./push_swap $ARG | wc -l
```

## Notes

- Efficient for very small numbers of elements (under 5).
- Advanced strategies applied for larger input sizes.
- Proper error management (non-numeric input, integer overflows, duplicates).
- No memory leaks (validated with `valgrind`).
- Fully functional `checker` program verifying your solutions.
- Custom `get_next_line` implementation for reading from `stdin`.

## Repository

Find the full project here: [42_Push_Swap Repository](https://github.com/Neuravoid/42_Push_Swap.git)

## License

This project is part of the 42 School curriculum and follows its academic honesty policy.
