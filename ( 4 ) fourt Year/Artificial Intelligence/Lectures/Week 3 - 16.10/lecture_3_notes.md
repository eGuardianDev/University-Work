# Lecture 3 – Local Search (cont.) and Constraint Satisfaction Problems

**Date:** 16.10.2026
**Subject:** ИИ (AI – Artificial Intelligence)
**Lecture:** Lecture 3 (Лекция 3)
**Week:** Week 3 (Седмица 3)
**Chapter:** Chapter 4, Section 3–4 – continuation

> **Note from the margin box:** "Насрочено(?) контролно – около 27–28" → *A test (quiz) is scheduled around the 27th–28th*

---

## TOC & introduction

The notes cover two pages. Page 1 continues Chapter 4 (local search) and starts Chapter 5 (constraint satisfaction). Page 2 contains a final remark on CSP performance and a summary of Chapter 6 (game playing).

**Table of contents**

1. [Page 1](#page-1)
   - Hill-climbing (continued) – landscape, objective function, local/global maxima, random start
   - Properties of simulated annealing
   - Local beam search
   - Genetic algorithms
   - Continuous state spaces
   - Chapter 5: Constraint Satisfaction Problem (CSP) – map coloring, cryptarithmetic
   - Backtracking search – heuristics, arc consistency
2. [Page 2](#page-2)
   - Complexity estimate for the search space
   - Iterative algorithms over CSP – performance of min-conflicts
   - Summary of Chapter 6 – Game playing
   - Games vs. search problems
   - Tic-tac-toe – Minimax
   - α-β pruning, meta-reasoning, resource limitation

---

# Page 1

## Hill-climbing (cont'd)

There is an objective function (в оригинал: "има целева функция → objective function" *(?)*).

Sketch of the state-space landscape (x-axis: states, y-axis: objective function value), with labels:

- **shoulder**
- **global max**
- **local max**
- **flat local max**
- **current state** (marked with a dot and an arrow pointing up the hill)

**Random start** (random-restart hill climbing)

## Properties of simulated annealing

*(heading only, no notes written below it)*

## Local Beam Search

- кокоши алгоритъм

## Genetic algorithms

- changing

$$
\text{Fitness} \rightarrow \text{Selection} \rightarrow \text{Pairs} \rightarrow \text{Crossover} \rightarrow \text{Mutation}
$$

## Continuous state spaces

*(heading only, no notes written below it)*

---

## Chapter 5 – Search Method: Constraint Satisfaction Problem (CSP)

### Constraint Satisfaction Problem

- Example: **Map-Coloring**
- variables 
   - тип - type
   - допустими стойности *(admissible/allowed values – domain)*

Съждителна и предикатна логика

### Cryptarithmetic

*(heading only, no notes written below it)*

---

### Backtracking search *(right-hand box)*

- Minimal remaining values
- Degree heuristic

→ **Arc Consistency**

---

# Page 2

*(No circled number on this page – it follows the previous page.)*

## Complexity estimate

$$
2^{80} = 4 \text{ милиарда години} \; (\text{4 billion years}) \text{ в 10 млн. nodes/ходове}\;
$$

$$
4 \cdot 20^{20}\;(?) = 0{,}4 \text{ секунди} \; (0.4 \text{ seconds}) \;\; —\!\!\!//\!\!\!—\!\!\!//\!\!\!—
$$

*(The "—//—" marks mean "the same (ditto)" as in the line above, i.e. at 10 million nodes/moves per second.)*

## Iterative algorithm over CSP

### Performance of min-conflicts

Sketch: graph with **CPU time** on the y-axis and **R** on the x-axis. Several curves stay low, rise sharply to a narrow peak, and then drop back near zero. The peak is marked as the **critical ratio**.

---

## Summary

# Chapter 6 – Game playing

- Games
  - perfect play
    - ↳ minimax decisions
    - ↳ $\alpha$–$\beta$ pruning
- Resource limit & approximate evaluation
- Games of chance
- Games of imperfect information

### Games vs. search problems

| | deterministic | chance |
|---|---|---|
| **perfect information** | chess | monopoly |
| **imperfect info** | battleships | poker |

### Tic-Tac-Toe – Minimax

Properties of minimax:

- Complete – for finite trees
- Optimal – Yes
- Time - ?
- Space - ?
- ? - ?

### $\alpha$–$\beta$ pruning

- (note from me) possible execution - priority queue – check next solution

### Meta-reasoning

### Resource limitation
