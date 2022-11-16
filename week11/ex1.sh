#!/bin/bash
sudo dd if=/dev/zero of=lofs.img bs=50MiB count=1
sudo losetup -f lofs.img
mystr=$(sudo losetup -j lofs.img | awk '{print $1}')
device=${mystr::-1}
sudo mkfs.ext4 "$device"
sudo mount "$device" lofsdisk