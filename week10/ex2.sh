#!/bin/bash
echo "Evsey 2" > ../week01/file.txt
link ../week01/file.txt _ex2.txt
inodenumber=$(stat -c '%i' ../week01/file.txt)
find . -inum "$inodenumber" > ex2.txt
find . -inum "$inodenumber" -exec rm {} \; >> ex2.txt
