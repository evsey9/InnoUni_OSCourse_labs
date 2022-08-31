#!/bin/bash

HISTFILE=~/.bash_history
set -o history

echo
echo
ls > /dev/null

history > ~/week1/ex2.txt
