# Javascript

## Insert into html
`<script src="code.js" defer>`
`defer` - donwload on the side

Javascript can be ran on browser console

`console.log()`

`console.error()`


няма нужда от точка и запетая, защото си ги добавя, но е добра практика.
## Sources
Разглеждане на код и неговото *debug*. Може да добавяме *breakpoints*


## Code
### Variables

`let name = "Maria"`
`const age = 32`

Избягвайте `var` защото се държи непредвидимо


`typeof <val>`
`typeof 3` - number

```js
let x;
typeof x; // undefined - още няма стойност, нещо не сработило като хората
```
```js
let x = null;
typeof x; // object - нарочно е null
```

```js
const course = 'Web';
const credit = 5;
console.log('Course ${source} is ${credits}');
```

TypeScript е типизирана версия на JavaScript.

Дори с грешки се изпълнява страницата в брузъра.


### Text editing
```js
let text = '  Web  ';
text.trim()
text.toLowerCase()
text.includes('web');
```

```js
const name = "Maria";
const name = "I'm student"; // ако използваме едните кавички, другите  няма да се видят
const name = 'Maria';
const name = '"random text"'; // същото като горе
```


### Bool checking
- `===` проверява и типа също! Доста полезно. Използвайте трите равно.
- `==` преобразува типовете и тогава ги сравнява
- `!==` отрицание

```js
5 === 5 // True
5 == 5  // True
5 === '5' // False
5 == '5' // True
```


#### If statements
Следните стойности ще върнат `false`: `false`,`0`,`undefined`,`null`

```js
if(false){
    console.log("false");
}
if(0){
    console.log("false");
}
if(undefined){
    console.log("false");
}
if(null){
    console.log("false");
}
```

`"0"`, `{}` - ще върнат `true`


### Arrays
```js
const fruits = ['apple', `banana`, `peach`];
```

```js
fruits[0] // броенето почва от 0
fruits.length // 3
let b = fruits.pop()
b // peach
fruits // apple, banana
fruits.includes('apple') // true
fruits.indexOf('banana') // 1
```

```js
prices = [3,20, 3.80, 2.50];

prices.forEach(price => console.log(price))


const withTax = prices.map(price => price *1.2) // returns array

const cheap = prices.filter(p => p > 3) // returns array
const cheap = prices.find(p => p > 3) // first element that satisfies the predicate


const total = price.reduce((sum,price) => sum + price, 0) 
// 0 is the starting value
```


### Struct
```js
const student = {
    name: 'Ivan',
    fn: `1234`,
    year: 4,
    courses: ['Web', 'AI']
}


student.name // Ivan
student['name'] // Ivan - used when the key is variable, not set by default

student.email = 'Ivan@abv.bg'

Object.entry() // ['key,'value'] -  key -> value
```
### Functions

```js

function add(a,b){
    return a + b
}

add(1,2,5) // 3
add(1) // NaN - 1 + undefined 
```

```js
const mutliply = (a,b) => a*b;
multiply(5,2) // 10
```

```js
function add(a=3,b=5){
    return a+b;
}

add() // 8
add(6) // 11
```

### Loops
```js
while(count > 0){

}

for()


```