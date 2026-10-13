
# Introduction

H(n) >=0 estimates the cost of the cheapest path from n to a goal. h(n) = 0 for every goal state,
it is an estimate cheap to compute and allowed to be wrong.


--- 
# Algorithms

## Greedy best-first

S node <- pop  Min(priority queue on h)

gets the best path here

Complete - no for tree. Yes if finite spcae
Optimal - no
Time - O($b^m$)
- b = branching factor
- m = maximal depth
- d = ??

Space - O($b^m$)


## Beam search and hill climbing
greedy ,but frontier is capped at $l$ nodes.
After each round, thorws away everything but the $l$ best by h.

- space drops to O($b*l$) constant in the depth

### hill climbing
- beam search but $l = 1$


## A*


### IDA* - iterative deepening A*

### A* с ограничена памет - memory-bound A* (SMA*)


## When on heuristic beats another

$h_2(n) >= h_1(n)$ for all n and both are admissible, $h_2$ dominantes $h_1$, and A* with $h_2$ never ...



## Heuristics for the 8-puzzle

$h_1$ = number of misplaced tiles(Hamming)

$h_2$ = total Manhattan distance

- Heuristic is simplifying the problem
    - допустимост и консистентност - трябва да правим проверки за пространството върху, което работим


## Simulated-Annealing


# Heuristics Евристика 
- допустима в граф
- консистентна в дърво

# Notes
- на контролното ще бъде домашното с модификация (домомента така е решено)
- научи таблиците на края на презентациите 