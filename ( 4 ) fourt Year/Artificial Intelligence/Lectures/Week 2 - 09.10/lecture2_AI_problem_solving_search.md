# Лекция 2 – Problem Solving & Search (Chapter 3)

**Дата:** 09.10.26 г. · **Предмет:** ИИ

---

## Страница 1

### Има я на формален изпит 

**Problem – задача**

- Problem solving agents
- Problem types
- Problem formulation
- Example problems
- Basic search algorithms

### Problem solving agents

- Problems formulated in terms of atomic states
- Offline problem solving

**Example: Romania**

- **Formulate goal:** be in Bucharest
- **Formulate problem:**
  - states: various cities
  - actions: drive between cities
- **Find solution:** sequence of cities
  *(is it optimal tho)*

### Problem types

- **Deterministic, fully-observable** → single state problem
- **Non-observable** – sensorless problem (conformant)
- **Non-deterministic / partially observable** → continous problem *(вероятно „contingency")*
  - Percepts provide new information about curr states
  - Solution is a contingent plan or a policy
  - Often interleave search, execution
- **Unknown state space** → exploration problem („online")

### Example: Vacuum world

- → 8 states, known start

---

## Страница 2

### Single-state problem formulation

- init state
- successor function S(x)
- goal test
- path cost (ex. distance)

### Selecting a state space

- Real world is absurdly complex
  - ↳ simplify (abstraction)
- state
- action

### Пространство от състояния – state space graph

- **search space** – всички състояния, достижими от началното състояние
- states
- actions
- goal test
- path cost

### Example: The 8 puzzle

- **states** – location of tiles
- **actions** – move blank left, right, top, down
- **goal test** = goal state
- **path cost** = 1 per move

### Example: robotic assembly

- **states** – robot joints
- **action** – move
- **goal** – complete assembly
- **path cost** – time to execute

> **Note:** Optimal solution of n-Puzzle family is NP-hard

### Tree search algorithms

- ↳ Implementations: states vs nodes

Критерии:

- completeness
- time complexity
- space complexity
- optimality

---

## Страница 3

### Uninformed search strategy

- Breadth-first search
- Uniform-cost search
- Depth-first search
- Iterative deepening search

### BFS

- **Complete:** Yes (if b is finite)
- **Time:** $1 + b + b^2 + b^3 + \dots + b^d + b(b^d - 1) = O(b^{d+1})$, i.e. exp in d
- **Space:** $O(b^{d+1})$ – keeps every node in memory
- **Optimal:** No, unless step costs are constant

### Uniform-cost search

- Зарвнопърно дърво *(?)* ~~(задраскано)~~
- Търсене

### Completeness!

- Защо: BFS и DFS са експоненциални?

### DFS

*(няма записки)*

- Iterative deepening search simulate BFS w/ DFS

### Repeated States

- ↳ Таблица с проверени състояния

