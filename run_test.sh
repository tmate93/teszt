#!/bin/bash

IFS=$'\n'

for i in `cat input.txt`; do
 echo "$i" >> output.txt
done