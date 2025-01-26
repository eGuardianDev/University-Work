#!/bin/bash


mkdir -p ./Tests/bin
echo "Begin compilation of tests"
g++ ./Tests/Tests.cpp ./src/implementation/*.cpp ./Tests/catch_amalgamated.cpp -o ./Tests/bin/testProgram.out

echo "Done compiling - Running tests:"


cd ./Tests/bin/
time ./testProgram.out

echo "End of bash"