#!/bin/bash

date
sleep 3
mkdir root_dir

date
sleep 3
mkdir home_dir

date
sleep 3
ls -t / | tac > root_dir/root.txt

date
sleep 3
ls -t ~ | tac > home_dir/home.txt

cat root_dir/root.txt
cat home_dir/home.txt
ls root_dir
ls home_dir
