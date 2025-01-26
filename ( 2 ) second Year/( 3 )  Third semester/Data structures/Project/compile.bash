#!/bin/bash
mkdir -p ./bin
g++ ./src/main.cpp ./src/implementation/*.cpp -o ./bin/a.out 

cd bin
./a.out input.txt