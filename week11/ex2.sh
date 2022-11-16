#!/bin/bash
echo "Evsey" | sudo tee ./lofsdisk/file1
echo "Antonovich" | sudo tee ./lofsdisk/file2
sudo cp --parents /bin/bash ./lofsdisk
sudo cp --parents /bin/cat ./lofsdisk
sudo cp --parents /bin/echo ./lofsdisk
sudo cp --parents /bin/ls ./lofsdisk
listbash="$(ldd /bin/bash | grep -E -o '/lib.*\.[0-9]')"
listcat="$(ldd /bin/cat | grep -E -o '/lib.*\.[0-9]')"
listecho="$(ldd /bin/echo | grep -E -o '/lib.*\.[0-9]')"
listls="$(ldd /bin/ls | grep -E -o '/lib.*\.[0-9]')"
for i in $listbash; do sudo cp -v --parents "$i" "./lofsdisk"; done
for i in $listcat; do sudo cp -v --parents "$i" "./lofsdisk"; done
for i in $listecho; do sudo cp -v --parents "$i" "./lofsdisk"; done
for i in $listls; do sudo cp -v --parents "$i" "./lofsdisk"; done

gcc ex2.c -o ex2
sudo cp ex2 lofsdisk/ex2
sudo chroot lofsdisk ./ex2 > ex2.txt
./ex2 >> ex2.txt
