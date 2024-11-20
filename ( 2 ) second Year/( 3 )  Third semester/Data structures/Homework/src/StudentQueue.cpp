

#include "StudentQueue.hpp"


Student StudentQueue::front(int time){
    if(!priority.empty() && (priority.front().TimeComing <= time)){
        return priority.front();
    }
    return normal.front();
}

void StudentQueue::pop(int time){
       if(!priority.empty() && (priority.front().TimeComing <= time)){
        priority.pop(); return;
    }
    normal.pop();
}

void StudentQueue::push(Student student){
    if(student.Course == 2){
        priority.push(student); return;
    }
    normal.push(student);
}
