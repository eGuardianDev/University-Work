#!/bin/bash

g++ main.cpp -o "StartGame.o" -Wall -Wextra -lcurses -g \
    $(pkg-config --cflags ncurses) \
    $(pkg-config --libs ncurses) \
    ./Controllers/*/*.cpp
    
./StartGame.o