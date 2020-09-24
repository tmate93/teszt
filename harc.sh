#!/bin/bash
IFS=$'\n'

rm kiementek.txt

echo ./a.out units/Hosarkany.json units/Sotetvarazslo.json >> kimenetek.txt
echo ./a.out units/Hosarkany.json units/Arnykiraly.json >> kimenetek.txt 
echo ./a.out units/Sotetvarazslo.json units/Hosarkany.json >> kimenetek.txt 
echo ./a.out units/Sotetvarazslo.json units/Arnykiraly.json >> kimenetek.txt 
echo ./a.out units/Arnykiraly.json units/Sotetvarazslo.json >> kimenetek.txt 
echo ./a.out units/Arnykiraly.json units/Hosarkany.json >> kimenetek.txt 

