#!/bin/bash
gcc channel.c -o channel
gcc publisher.c -o publisher
gcc subscriber.c -o subscriber

./channel

for i in $(seq "$1")
do
  konsole -e ./subscriber "$1" &
done

./publisher "$1"