#!/bin/bash

IFS=$'\n'

for i in `cat input.txt`
do
 echo "Szamok: $i, sz:"
 echo "$i" | sh ./a.out 
done