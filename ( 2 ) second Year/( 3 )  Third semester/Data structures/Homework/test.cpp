
#include <cstdint>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

// void processValue(std::uint8_t value) {
//     std::cout << (short)value;
// }
// std::vector<int> steps;

#include "src/Student.hpp"

std::priority_queue<Student,std::vector<Student>,CompareStudentNeededTime> priorityStud;

int main() {

    priorityStud.push(Student(1,1,3,3));
    priorityStud.push(Student(0,2,2,2));

    std::cout << (int)priorityStud.top().Id;

    // int x = 42;  // Within the range of uint8_t
    // processValue(x);  // Implicit conversion happens
    return 0;
}