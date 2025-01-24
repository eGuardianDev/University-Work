# ThisFunc - интрепретатор
Проект на Цветомир Стайков
КН – 2група - 1MI0800469

---

#### Интрепретатор на функционален език


[Guide](
https://craftinginterpreters.com/scanning.html#the-interpreter-framework)



#### Проучване
 - Lexer - взема вход и го праави на tokens

 - Parser - взема tokens, връща синтактично дърво

 - Interpreter - взема синтактично дърво и изчислява резултата


#### Syntax

- [X] add - 2 arguments 
- [X] sub - 2 arguments  
- [X] mul - 2 arguments
- [X] div - 2 arguments
- [] pow - 2 arguments
- [] sqrt - 1 arguments
- [] sin - 1 arguments
- [] cos - 1 arguments
- [] eq - 2 arguments -> equal ==
- [] le - 2 arguments -> less  <
- [] nand - 2 arguments -> not and  !#0 || !#1

- [X] IF - 3 arguments - "test" "if-true" "if-false"
- [X] list - random arguments - 
- [X] head - 1 argument - list -> first element
- [X] tail - 1 argument - list -> new list
- [X] map - 2 arguments - "function-name" "list" -> new list
- [X] filter - 2 arguments - "function-name" "list" -> new list

lazy evaluation - if, nand

eq(#0, #1) -> #0 е първия аругмент, #1 е втория аргумнет и т.н

---

Обработка на грешки...

---

Рекурсия...

---


## Todo:
 - [X] same alloc when error clean memory (check with isNewlyAllocated() )
 - [] don't allow rewritting default functions
 
 - [X] lists;
 - [X] read from file
 
 - [] copy/move semantics
 - [X] save trees that don't need evaluation

 - [X] evaluate trees with no arguments needed
        - Fixed const values being delted
 - fixed empty list not implemented
 
 - [] if function haven't declared all it's values, don't execute
 - [] allow to check how many arguments functions has, without solo tests ( or create a function for that );