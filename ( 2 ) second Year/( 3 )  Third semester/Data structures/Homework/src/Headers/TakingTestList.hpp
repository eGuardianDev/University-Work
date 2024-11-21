
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
    TakingTestList(){
        head = nullptr;
        size = 0;
    }

    ~TakingTestList(){
        clear();
        size = 0;
    }
    TakingTestList(const TakingTestList& other){
        copy(other.head);
        this->size = other.size;
    }

    TakingTestList& operator=(const TakingTestList& other){
        if(this != &other){
            clear();
            this->size = other. size;
            copy(other.head);
        }
        return *this;
    }

    TakingTestList(TakingTestList&& other){
        this->head = other.head;
        other.head = nullptr;

        this->size = other.size;
        other.size = 0;
    }
    TakingTestList& operator=(TakingTestList&& other){
        if(this != &other){
            clear();
            this->head = other.head;
            other.head = nullptr;
            
            this->size = other.size;
            other.size = 0;
        }

        return *this;
    }

    const int Size() const {
        return size;
    }


    void copy(Node* other){
        assert(other);
        if(other == nullptr) return;
        
        
        Node* current = new Node(other->student);
        Node* otherPointer = other;
        otherPointer = otherPointer->next;
        head = current;
        
        while(otherPointer){
            current->next = new Node(otherPointer->student);
            current = current->next;
            otherPointer = otherPointer->next;
        }
    }

    bool Inbetween(Student student, Node* current){
        if(current->next == nullptr){
            return false;
        }
        int nodeTime = current->student.getTimeComing() + current->student.getTimeNeeded();
        int studentTime = student.getTimeComing() + student.getTimeNeeded();

        int nextNodeTime = current->next->student.getTimeComing() +current->next->student.getTimeNeeded();
        
        return (nodeTime <= studentTime) && (studentTime < nextNodeTime);
    }

    void push(Student student){
        if(head == nullptr){
            head = new Node(student);
            ++size;
            return;
        }

        Node* curr = head;

        int studentTime = student.getTimeComing() + student.getTimeNeeded();
        
        if(curr->student.getTimeComing()+
           curr->student.getTimeNeeded() > studentTime){
            Node* temp = new Node(student);
            temp->next = head;
            head = temp;
            ++size;
            return;
        }

        while(curr->next != nullptr){     
            if(Inbetween(student, curr)){
                Node* temp = curr->next;
                curr->next = new Node(student);
                curr->next->next = temp; 
                ++size;
                return;
            }
            curr = curr->next; 
        }

        curr->next = new Node(student);
        ++size;
       
    }
    Student& top(){
        return head->student;
    }
    void pop(){
        Node* temp = head;
        head = head->next;
        delete temp;
        --size;
    }
    bool empty(){
        return head==nullptr && size == 0;
    }

    void clear(){
        Node* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }




private:
 

    int size;
    Node* head; 
};



#endif //  __TAKING_TEST_LIST_HPP_