#!/bin/bash
IFS=$'\n'

./a.out units/Hosarkany.json units/Sotetvarazslo.json 
./a.out units/Hosarkany.json units/Arnykiraly.json 
./a.out units/Sotetvarazslo.json units/Hosarkany.json 
./a.out units/Sotetvarazslo.json units/Arnykiraly.json 
./a.out units/Arnykiraly.json units/Sotetvarazslo.json 
./a.out units/Arnykiraly.json units/Hosarkany.json 

