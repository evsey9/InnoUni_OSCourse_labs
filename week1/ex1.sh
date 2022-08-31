#!/bin/bash

pattern="gcc"
find /usr/bin -name "*${pattern}*" | sort -r | tail -n 5 > ex1.txt
