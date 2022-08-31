#!/bin/bash

pattern="driver"
find /proc -name $pattern > output.txt 2> errors.txt
sort output.txt | head -n 3
sort errors.txt | head -n 3
