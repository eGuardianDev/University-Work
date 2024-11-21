

#ifndef __STUDENT_HPP_
#define __STUDENT_HPP_


#include <cstdint>
struct Student{

    short TimeComing;
    uint8_t Id; // ! Range between [1,256] 
    uint8_t Course;
    short TimeNeeded;


    // * Use this function when output to console
    int getTimeNeeded(){return (int)TimeNeeded;}
    // * getId() mainly because of this or it won't show
    int getId(){return (int)Id+1;} 
    int getCourse(){return (int)Course;}
    int getTimeComing(){return (int)TimeComing;}
   

    Student(uint8_t timeComing, uint8_t id,uint8_t timeNeeded, uint8_t course) : TimeComing(timeComing), Id(id), Course(course), TimeNeeded(timeNeeded) {}


};


// * Used in priority queue
// struct CompareStudentNeededTime{

// public:
//     bool operator()(Student& lhs, Student& rhs){
//         return lhs.TimeComing+lhs.TimeNeeded >
//               rhs.TimeComing+rhs.TimeNeeded;
//     }
// };


#endif