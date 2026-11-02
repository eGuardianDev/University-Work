# Планиране (Planning) – Глава 11

**Дата:** 30.10.2026
**Предмет:** ИИ (Изкуствен интелект – AI) *(?)*
**Седмица:** 5 (Седмица 5)
**Глава:** Chapter 11: Planning

> **Бележка:** Темата за експертни системи (expert systems) няма да се гледа.

---

## TOC & introduction

Записките въвеждат планирането (planning) в изкуствения интелект: какво е планиране, защо пълното изчерпване е непрактично, какви свойства трябва да има езикът за планиране и как STRIPS представя състояния, цели и действия. В края са изброени темите за следващата лекция и датата на контролното.

**Съдържание**

1. [Страница 1](#страница-1)
   - Какво е планиране
   - Сложни реални проблеми
   - Език за планиране (Planning language)
2. [Страница 2](#страница-2)
   - Общи характеристики на езика (General Language Features)
   - Представяне на състояния
   - Предположение за затворен свят (Closed World Assumption)
   - Представяне на цели
   - Представяне на действия
3. [Страница 3](#страница-3)
   - Семантика на езика (Language Semantics)
   - Изразителност и разширения (Expressiveness & extensions)
   - Пример
4. [Страница 4](#страница-4)
   - Теми за следващата лекция
   - Контролно

---

# Страница 1

## Какво е планиране

Генериране на стъпки за достигане на цел.

## Сложни реални проблеми

- Какви действия са нужни?
  - Изчерпващо търсене (Exhaustive search)
  - Обратно търсене (Backward search)
- Каква е добра евристична функция?
  - добра оценка (estimation) за цената на фаза
  - проблеми зависими / независими
- Декомпозиране на проблема (Decompose the problem)?
  - Повечето реални проблеми са почти декомпозируеми (Most real-world problems are nearly decomposable)

### Лични бележки (дясна страна)

> Пълното изчерпване (exhaustive) е невъзможно заради *(?)* и трябва евристика. *(?)*

## Език за планиране (Planning language?)

- ↳ Добър ли е такъв език?
  - Достатъчно изразителен, за да описва много проблеми (Expressive enough to describe many problems)
  - Достатъчно ограничаващ, за да позволява ефективни алгоритми (Restrictive enough to allow efficient algorithms)
  - Алгоритъмът за планиране трябва да може да се възползва от локалната структура на проблемите (Planning algorithm should be able to take advantage of the local structure of the problems)

**STRIPS & ADL**

---

# Страница 2

*(Без номер в кръг – следва предишната страница.)*

## Общи характеристики на езика (General Language Features)

### Представяне на състояния (Representation of States)

- Разлагане на света на логически условия и представяне на състоянието като конюнкция от положителни литерали (Decompose the world into logical conditions & present a state as a conjunction of positive literals)
  - Пропозиционални литерали (Propositional literals): $Poor \land Unknown$
  - Литерали от първи ред (First-Order, FO): *grounded* и без функции (grounded & function free)

$$
At(Plane_1, Melbourne) \land At(Plane_2, Sydney)
$$

**Бележка в кутия (вдясно):** *grounded* – *(?)* (цяла стойност *(?)*)

### Предположение за затворен свят (Closed World Assumption)

Всичко, което не е експлицитно зададено като вярно, е грешно (не се знае → приема се за невярно) *(?)*.

### Представяне на цели (Representation of Goals)

- Частично зададено състояние, представено като конюнкция от положителни базови литерали (Partially specified state & represented as a conjunction of positive ground literal)
- Целта е постигната (goal is achieved / satisfied), ако състоянието съдържа всички литерали на целта *(?)*

### Представяне на действия (Representation of Actions)

- Действие = предусловие + ефект (Action = precondition + effect)

```
Action(Fly(Plane, from, to))
    Precondition: At(p, from) ∧ Plane(p) ∧ Airport(from) ∧ Airport(to)
    Effect:       ¬At(p, from) ∧ At(p, to)
```

$$
\text{Precondition: } At(p, from) \land Plane(p) \land Airport(from) \land Airport(to)
$$

$$
\text{Effect: } \lnot At(p, from) \land At(p, to)
$$

---

# Страница 3

*(Номер ② в кръг в горния десен ъгъл.)*

## Семантика на езика (Language Semantics?)

- Как действията (actions) влияят на състоянията (affect states)
- Резултатът от изпълнението на действие $a$ в състояние $s$ е състоянието $s'$ *(?)*
  - Предположение на STRIPS (STRIPS assumption), за избягване на представителния проблем на рамката (avoid representational frame problem): всеки литерал, който НЕ е в ефекта, остава непроменен (every literal NOT in the effect won't be *(changed)* *(?)*)

## Изразителност и разширения (Expressiveness & extensions)

- STRIPS е прост сам по себе си (simple itself)
  - ↳ ограничение: литерали без функции (function-free literal) ← **важно (important)**
- Разширение: Език за описание на действия (Action Description Language, **ADL**)

---

## Пример (Example)

```
Init(__ ∧ __ ∧ __ ∧ ...)
Goal(At(__) ∧ At(__))

Action
    Precond
    Effect

Action
    Precond
    Effect

Action
    Precond
    Effect
```

$$
Init(\_\_ \land \_\_ \land \_\_ \land \dots) \qquad Goal(At(\_\_) \land At(\_\_))
$$

---

# Страница 4

*(Без номер – следва предишната страница. В горния десен ъгъл се вижда датата 30.10.26г.)*

## Теми за следващата лекция

- Алгоритми за прогресия (Progression Algorithms) ?
- Алгоритми за регресия (Regression Algorithms)
- Планиране с частична подредба (Partial-Order Planning, **POP**)
- Решаване на POP (Solving POP)

---

## Контролно

**28 Ноември, 10 часа** – *Контролно* на материала от лекциите.
