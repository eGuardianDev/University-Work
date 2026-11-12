# PHP

## Intro
- interpreted
- server-side side - send only html, css, javascript

php code isn't seen, just the final stuff

### usase
- javascript - interfactivity
- php - data management 

## running php

- **XAMPP**
- online programs

## Code writing 
`<?= ... ?>` - inline php

```php
<?php
    echo '<h1> hello </h1>'
?>
```

```php
$name = 'Maria';
$age = 20;
$grade = 5.5;
$isStudent = true;

echo 'Име:' . $name
echo 'Име: $name' // not good
```
in javascript

```js
'name' + var;
```


- Полвайте стого стравнение с `===`
- стойност подразбиране `??` - `$_GET['name] ?? 'гост'` - тоест ако не върне нищо ще върне това


## If statement

- `elseif` е слято


## array

`$fruits[] = 'kiwi'`

`foreach($fruits as $fruit){}`


### асоциативен масив

```php
$student =[
    'name' => 'Ivan',
    'age' => '20',
];

echo $student['name'];

foreach($student as $key=>$value){
    echo 'key: ' . $key . ' value: ' . $value;
}
```


date('d.m.Y');

var_dump();