### дефиниране на факти (facts)

```
male(albert).
male(bob).

female(alice).
```


Така може да минем през всичките чрез: 


``` 
?- male(X), femaly(Y).
```

И това ще даде всички връзки

X = albert
Y = alice ? 

след ? слагаме ; и това ще даде следващата стъпка


### дефиниране на правила (rules)

```
swims(x) :- 
  happy(x),
  near_water(x).
```


### дефиниране на променливи

```
female(X).
```

```
parent(X,bob).
```

#### Анонимни променливи

```
?- hates(romeo, X).

X = someone

yes
```

Алтернативно
```
?- hates(romeo, _).

yes
```



### начални променливи
Може да сложим базови променливи така, че ако има нещо от този вид да се извика специфична функция.
```
check_if(5):-
  ...

check_if(6):-
  ...

check_if(x):-
  ...
```



### is 
изполване на `is` е като `=`



### Equal
```
`alice` = alice.
yes
```

### Not equal
```
\+ (alice = albert).
yes
```

### less than
```
3 =< 5
3 >= 5
```



### trace.
можем да следим как се изпълнява даден предикат

### notrace.
спира горното


### list

```
length([1,2,3],X)

X = 3
```

```
[H|T] = [1,2,3]

H = a
T = [2,3]
```


```
[T1,T2,T3,T4|T] = [1,a,b,c]

T = []
T1 = 1
T2=a
T3=b
T4=c
```

```
[_,T2,_,_|T] = [1,a,b,c]

T = []
T2=a
```

also do list inside list

# programming pattern
sometimes we store values in specific variables
or we just check for specific true/false value
