#!/bin/bash

# Generate 500 unique random numbers, save to numbers.txt
shuf -i 1-10000 -n 500 | paste -sd ' ' - > numbers.txt

# Run push_swap on numbers, save output moves to instruction.txt
./push_swap $(cat numbers.txt) > instruction.txt
