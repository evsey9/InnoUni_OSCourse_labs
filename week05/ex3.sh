#!/bin/bash
gcc -pthread ex3.c -o ex3
rm -f ex3.txt

echo "m: 1" >> ex3.txt
{ time ./ex3 10000000 1 ; } 2>> ex3.txt

echo "m: 2" >> ex3.txt
{ time ./ex3 10000000 2 ; } 2>> ex3.txt

echo "m: 4" >> ex3.txt
{ time ./ex3 10000000 4 ; } 2>> ex3.txt

echo "m: 10" >> ex3.txt
{ time ./ex3 10000000 10 ; } 2>> ex3.txt

echo "m: 100" >> ex3.txt
{ time ./ex3 10000000 100 ; } 2>> ex3.txt