## Simulation of exam

Homework for Course - Data Structures.

Developed by Tsvetomir Staykov

---
### Development enviroment

Developed and tested on - **Linux Fedora 40**

#### compile

To compile and running on **Linux** use
```
./compile.bash
```
or
```
g++ ./src/main.cpp ./src/Implementation/*.cpp -o ./bin/a.out
 ```
check `/bin/` for compiled files

The program needs `input.txt` to run 

#### Tests
Library used - **Catch**

To compile and running tests on **Linux** use
```
./compileTests.bash
```
check `/Tests/bin/` for compiled files 

(I don't know CMake, yet)

---

### Quick introduction
The project begins in `/src/main.cpp`

To compile on your own you need to to include `/src/Implementation/*.cpp`

All headers files are in `/src/Headers/`

Almost all of the implemеntations and additional programs the code are in `/src/Implementation/`


### Algorithm for board
The algorthim starts recursion, places the person and checks if this is the best configuration. (best configuration meaning most people on board) If so it saves it. Then continues. 

After filling the board one times, It stars going back. On every step going back, It tries to find better way to fill the board by checking how much space the currently placed person taken around them. When going back, It removes the person first placed and tries on a new location. If the new configuration takes less space, the recursion starts again forward again.

The problem here is that the count of space taken is saved locally in function when the recursion is called. This leads to similar configurations being checked repeatedly. Because of that, the **altered version** of the algorithm can be used to save count globally using vector. Scroll down to see how to activate it.

### Classes 

#### addons
Additional tools for displaying the board and class *Pair*

#### Board 
Class used to generate boards and place characters on it.

#### People on board
Algorthim for finding the best way to position people in a exam hall. In the implementation folder show two algorithms than can be switched using

```// #define _Using_Altered_Algorithm```
Removing the comments will let the compile use the **altered version**. Unneccessery for small boards

#### Student
Base structure for holding information about the students

#### Student queue
Queue with sorted people based on time of arriving
Uses 2 queues and modified pop and top for removing people

#### TakingTestList
Queue with sorted people based on time until finish. Uses my own implementaion with big 6 (ctor,dtor, copy and move semantics). The only class with pointers.

#### Main logic
Loading the data from file, running the algorithms for letting people in, removing them when they are done and checking their work.

### What I learned from this homework
Asserts were very useful for funding problems early on. 

Tests helped me see a few minor bugs. 

Queues return default value if empty and don't throw exceptions 