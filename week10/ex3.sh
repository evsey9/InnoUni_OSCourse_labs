#!/bin/bash
echo "Evsey 3" > _ex3.txt
chmod a-x _ex3.txt > ex3.txt
chmod uo+rwx _ex3.txt >> ex3.txt
chmod g=u _ex3.txt >> ex3.txt
echo "660 means owner can read and write, group can read and write, and others cannot read/write/execute" >> ex3.txt
echo "775 means owner can read/write/execute, group can read/write/execute, others can read and execute" >> ex3.txt
echo "777 means everyone can read/write/execute" >> ex3.txt