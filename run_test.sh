#!/bin/bash

IFS=$'\n'

rm output.txt

for i in `cat input.txt`; do
 echo "$i" >> output.txt
done