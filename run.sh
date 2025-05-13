#!/bin/bash

# Usage: run_seed_zero.sh [seed]
# If no seed is provided, it defaults to 0.

n=${1:-0}
file=$(printf "%04d" "$n")
mkdir -p tools/out

# Compile
g++ -std=c++20 -O2 -o a.out src/main.cpp

# Run and Judge
./a.out < tools/in/${file}.txt > tools/out/${file}.txt
cargo run -r --bin vis tools/in/${file}.txt > tools/out/${file}.txt

# If interactive problem, run the following command
# cargo run -r --bin tester ./a.out < tools/in/${file}.txt > tools/out/${file}.txt
