#include <iostream>

/*

|         |
|         |
|         |
|pointer  | heap -> int(1)
|func     |  
|char  'a'|
|int  -19 | <- 0xa3
|int    3 |
------
Stack


 ____________________
|     int(1)         | <- 0x09
|                    |
|                    |
|                    |
|                    |
----------------------
Heap

*/




void func(){
    return;
}
int main(){


    int a = 3;
    int b = 4;
    char c = 'a';
    func();

    int *point = new int(1);

    std::cout <<"pointer = &     new int(1) = " << point <<'\n';
    std::cout<< "& pointer = " << &point <<'\n';
    std::cout<< "*pointer = new int(1) = " << *point <<'\n';
    


    return 0;
}