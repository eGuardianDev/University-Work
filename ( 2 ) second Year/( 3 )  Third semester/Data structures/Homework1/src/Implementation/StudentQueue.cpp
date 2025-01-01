

#include "../Headers/StudentQueue.hpp"


Student& StudentQueue::front(int time){
    if(!priority.empty() && (priority.front().getTimeComing() <= time)){
        return priority.front();
    }
    return normal.front();
}

void StudentQueue::pop(int time){
       if(!priority.empty() && (priority.front().getTimeComing() <= time)){
        priority.pop(); return;
    }
    normal.pop();
}

void StudentQueue::push(Student student){
    if(student.getCourse() == 2){
        priority.push(student); return;
    }
    normal.push(student);
}
