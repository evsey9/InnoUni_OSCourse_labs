#!/bin/bash

mkdir ~/week1
cd ~/week1

pattern="gcc"
find /usr/bin -name "*${pattern}*" | sort -r | tail -n 5 > ~/week1/ex1.txt
