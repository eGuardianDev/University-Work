

#ifndef __STUDENT_HPP_
#define __STUDENT_HPP_


#include <cstdint>
struct Student{

    short TimeComing;
    uint8_t Id;
    uint8_t Course;
    short TimeNeeded;

    int getTimeNeeded(){return (int)TimeNeeded;}
    int getId(){return (int)Id;}
    int getCourse(){return (int)Course;}
    int getTimeComing(){return (int)TimeComing;}
   

    Student(uint8_t timeComing, uint8_t id,uint8_t timeNeeded, uint8_t course) : TimeComing(timeComing), Id(id), Course(course), TimeNeeded(timeNeeded) {}


};

struct CompareStudentNeededTime{

public:
    bool operator()(Student& lhs, Student& rhs){
        return lhs.TimeComing+lhs.TimeNeeded >
              rhs.TimeComing+rhs.TimeNeeded;
    }
};


#endif