
#ifndef __TAKING_TEST_LIST_HPP_
#define  __TAKING_TEST_LIST_HPP_

#include "Student.hpp"
#include <cassert>

class TakingTestList{
private:
   struct Node{
        Student student;
        Node* next;
        Node(Student& _student, Node* _next = nullptr ) 
        : student(_student), next(_next){ }
    };

public:
    TakingTestList();
    ~TakingTestList();

    TakingTestList(const TakingTestList& other);
    TakingTestList& operator=(const TakingTestList& other);

    TakingTestList(TakingTestList&& other);
    TakingTestList& operator=(TakingTestList&& other);

    const int Size() const;

    void push(Student student);

    Student& front();

    void pop();

    bool empty() const;

    void clear();


private:

    void copy(Node* other);
    friend void swap(TakingTestList& first, TakingTestList& second);

    bool Inbetween(Student student, Node* current) const;

    int size;
    Node* head; 
};



#endif //  __TAKING_TEST_LIST_HPP_