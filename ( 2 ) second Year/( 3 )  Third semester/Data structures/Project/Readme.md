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


#### syntaxis

- add - 2 arguments
- sub - 2 arguments
- mul - 2 arguments
- div - 2 arguments
- pow - 2 arguments
- sqrt - 1 arguments
- sin - 1 arguments
- cos - 1 arguments
- eq - 2 arguments -> equal == 
- le - 2 arguments
- nand - 2 arguments

- IF - 3 arguments - "test" "if-true" "if-false"
- list - random arguments - 
- head - 1 argument - list -> first element
- tail - 1 argument - list -> new list
- map - 2 arguments - "function-name" "list" -> new list
- filter - 2 arguments - "function-name" "list" -> new list

lazy evaluation - if, nand

eq(#0, #1) -> #0 е първия аругмент, #1 е втория аргумнет и т.н

---

Обработка на грешки...

---

Рекурсия...

---


