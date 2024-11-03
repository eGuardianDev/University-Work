#include <ios>
#include <iostream>
#include "stack.hpp"

int main(){
    
    LinkedStack<int> stack;
    LinkedStack<int> stack2;



    stack.push(1);
    stack.push(2);

    stack2 = stack;
    std::cout << stack2.top();

    return 0;
}