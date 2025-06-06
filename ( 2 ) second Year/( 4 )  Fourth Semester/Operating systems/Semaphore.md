# Semaphore tactics

## release the chickens
Ако трябева един процес да пусне друг и той има копия

примерно R пуска копията на Q 

тогава може да се изпозлва
```
//Q
semaphore.wait();
semaphore.signal();
```
така като едно Q тръгне, всички тръгват след него


## one time execusion
Ако трябва да изпълним примерно един път кода на R тогава може да направим bool
```
// R 
semaphore.wait()
if cnt == 0
  cnt = 1
semaphore.signal();
...
```
