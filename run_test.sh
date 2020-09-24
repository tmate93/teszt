#!/bin/bash

IFS=$'\n'

rm output.txt

cat input.txt

for i in `cat input.txt`; do
 echo "Szamok: $i, lko:"
 echo "$i" | ./a.out
done
