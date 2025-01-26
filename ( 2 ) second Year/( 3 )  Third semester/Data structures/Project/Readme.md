# ThisFunc - интрепретатор
Проект на Цветомир Стайков
КН – 2група - 1MI0800469

---

#### Интрепретатор на функционален език


[Used guide](
https://craftinginterpreters.com/scanning.html#the-interpreter-framework)

### Среда на разработка и процес

Програмирано и тествано на - **Linux Fedora 40**


### Класове 
 - Lexer - взема вход и го превръща в "Tokens".
 - tokenChecker - проверява дали дадени "Tokens" спазват структурата на езика.
 - Parser - взема "Tokens", връща синтактично дърво.
 - Interpreter - взема синтактично дърво и изчислява резултата.


#### Функции

- [X] add - 2 аргумента 
- [X] sub - 2 аргумента  
- [X] mul - 2 аргумента
- [X] div - 2 аргумента
- [X] pow - 2 аргумента
- [X] sqrt - 1 аргумента
- [X] sin - 1 аргумента
- [X] cos - 1 аргумента
- [X] eq - 2 аргумента -> equal ==
- [X] le - 2 аргумента -> less  <
- [X] nand - 2 аргумента -> not and  !#0 || !#1

- [X] if - 3 аргумента - "test" "if-true" "if-false"
- [X] list - random аргумента - 
- [X] head - 1 argument - list -> first element
- [X] tail - 1 argument - list -> new list
- [X] map - 2 аргумента - "function-name" "list" -> new list
- [X] filter - 2 аргумента - "function-name" "list" -> new list

 - "lazy evaluation" за if
 - Обработка на грешки - поддържано
 - Рекурсия - 

 - Дефинирани на фукнции от потребителя с няколко аргумента (function overloading)
 - Преизчисляване на функции, който не получават аргументи


