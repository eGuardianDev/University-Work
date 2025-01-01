#!/bin/bash
mkdir -p ./bin
g++ ./src/main.cpp ./src/Implementation/*.cpp -o ./bin/a.out

cd bin
./a.out