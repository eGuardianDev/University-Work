#!/bin/bash

g++ 5.cpp

start=`date +%S`

echo "starting the program"
./a.out <<< '8 0 0 ' # with 8 4 0 is faster
echo "end of program"
end=`date +%S`
echo Execution time was `expr $end - $start` seconds.