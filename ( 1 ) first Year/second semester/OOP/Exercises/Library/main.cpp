#include <iostream>
#include <cstring>
#include "Book.h"
#include "Person.h"

int main(){
    std::cout << "Hello World!\n";
    Book b("Hello", " World", 1);
    char* nameOfP;
    strcpy(nameOfP, "asd");
    Person p(nameOfP, 1, 'm');
    std::cout << b.getName() << "\n";
    std::cout << p.getName();
    return 0;
}