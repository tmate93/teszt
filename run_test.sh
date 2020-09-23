#!/bin/bash

IFS=$'\n'

for i in `cat input.txt`
do
 echo "Szamok: $i, sz:","$i" | ./a.out
done