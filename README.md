*This project has been created as part of the 42 curriculum by fbendnan.*

# push_swap

## Description

push_swap is an algorithmic project from the 42 curriculum focused on sorting a list
of integers using two stacks (a and b) and a limited set of operations.

The goal of the project is to output the smallest possible sequence of operations
that sorts stack a in ascending order, while following strict constraints on allowed
instructions.

This project emphasizes:
- algorithmic thinking
- data structure manipulation (linked lists)
- optimization under constraints
- time and space complexity awareness

Two programs are produced:
- push_swap: generates the sorting instructions
- checker: verifies that the instructions correctly sort the stack

## Instructions

Compilation:

make

make clean
make fclean
make re

Usage:

./push_swap 3 2 1

Example output:
sa
rra

Checker:

./push_swap 3 2 1 | ./checker 3 2 1

Output:
OK

If the result is not correctly sorted:
KO

Allowed Operations:

sa   swap the first two elements of stack a
sb   swap the first two elements of stack b
ss   sa and sb at the same time
pa   push the top of stack b to stack a
pb   push the top of stack a to stack b
ra   rotate stack a up
rb   rotate stack b up
rr   ra and rb at the same time
rra  reverse rotate stack a
rrb  reverse rotate stack b
rrr  rra and rrb at the same time

## Algorithm Overview

The project uses different strategies depending on input size:

- 2–3 elements: direct comparisons and swaps
- 4–5 elements: push smallest elements to stack b, sort remaining, then reinsert
- Large inputs (100–500):
  - values are ranked
  - stack a is divided into chunks
  - elements are pushed to b chunk by chunk
  - maximum values are pushed back to a in optimal order

## Error Handling

The program handles the following errors:
- non-numeric arguments
- duplicated numbers
- integer overflow or underflow
- empty or space-only arguments

On error, the program prints:
Error
to stderr and exits.

## Resources

References:

Stack data structure:
https://www.youtube.com/watch?v=i1pbAozGl0U&list=PLZpzLuUp9qXyWylaS9C8Z4uIKWZxQc3Cq

Sorting algorithms:
https://en.wikipedia.org/wiki/Sorting_algorithm
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

AI Usage:

Artificial Intelligence tools (ChatGPT) were used during this project for:
- debugging segmentation faults
- improving code clarity and structure

All algorithmic decisions, implementations, and optimizations were designed and coded by the author.

## Author

Fatima zahra Bendnane
42 Network student
