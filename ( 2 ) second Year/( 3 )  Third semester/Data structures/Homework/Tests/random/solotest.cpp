#include "../../src/Headers/Student.hpp"
#include "../../src/Headers/TakingTestList.hpp"
#include <iostream>


int main(){

    TakingTestList list;

    list.push(Student(0,0,0,0));


    TakingTestList list2;
    std::cout << list.Size();
    list2 = list;
    std::cout << list2.Size();
    list2.pop();
    return 0;
}