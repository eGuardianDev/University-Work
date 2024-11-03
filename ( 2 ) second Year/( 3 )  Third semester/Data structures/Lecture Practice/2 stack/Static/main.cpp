#include <ios>
#include <iostream>

#include "stack.hpp"

int main(){

    stack tempStack(1);
    tempStack.push(12);
    
    
    std::cout << "is Empty: "<< std::boolalpha << tempStack.isEmpty() << "\n";
    std::cout << "is Full: " << tempStack.isFull() << "\n";
    std::cout << "top: " << tempStack.top() << '\n';
    std::cout << "pop: " << tempStack.pop() << '\n';

    std::cout << "is Empty: "<< std::boolalpha << tempStack.isEmpty() << "\n";
    std::cout << "is Full: " << tempStack.isFull() << "\n";
    tempStack.push(123);
    tempStack.push(123);
    

    return 0;
}