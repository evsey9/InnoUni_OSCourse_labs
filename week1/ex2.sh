#!/bin/bash

HISTFILE=~/.bash_history
set -o history

echo
echo
ls > /dev/null

history > ex2.txt
