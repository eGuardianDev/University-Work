

#ifndef __STUDENTS_QUEUE_HPP_
#define __STUDENTS_QUEUE_HPP_

#include "Student.hpp"
#include <queue>

class StudentQueue{

public:
    Student front(int time);

    void pop(int time);
    
    void push(Student);

    bool isEmpty() const {return priority.empty() && normal.empty();}

private:
    std::queue<Student> priority;
    std::queue<Student> normal;
};



#endif