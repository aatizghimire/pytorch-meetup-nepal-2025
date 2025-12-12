#!/bin/bash

echo "-----------------------------------"
echo "Compiling with -O0 (No Optimization)"
gcc -O0 test.c -o test0
echo "Running test0..."
./test0

echo "-----------------------------------"
echo "Compiling with -O1 (Basic Optimization)"
gcc -O1 test.c -o test1
echo "Running test1..."
./test1

echo "-----------------------------------"
echo "Compiling with -O2 (High Optimization)"
gcc -O2 test.c -o test2
echo "Running test2..."
./test2
