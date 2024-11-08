#pragma once

#include <algorithm>

template<class T>
class LList {

public:
    struct Node{
        T value;
        Node *next;
        Node() {

        }
    };

    LList() : head(nullptr), tail(nullptr){
        
    }

    //copy
    LList(const LList<T> &other) : LList(){
        copy(other);
    } 
    LList& operator=(const LList<T> &other){
        if(&other == this) return * this;
        free();
        copy(other);
        return *this;
    }

    //move
    LList(LList<T> &&other) : head(other.head), tail(other.tail){
        other.head = nullptr;
        other.tail = nullptr;
    }
    LList& operator=(LList<T> &&other){
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        return *this;
    }
    
    void free(){
        while(head){
            Node* temp = head;
            head= head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    
    }
    ~LList(){
        free();
    }


    void push_front(const T &value){
        Node* temp = new Node{value, head};
        if(!head){
            tail = temp;
        }
        head = temp;
    }

    void push_back(const T &value){
        Node* temp = new Node{value, nullptr};
       
        if(tail != nullptr){
            tail->next = temp;
        }else{
            head = temp;
        }
       
        tail = temp;
    }

private:

    Node* head;
    Node* tail;

    //call this on empty list
    void copy(const LList<T> &other){
        if(!other.head) return;
        for(Node * curr = other.head; curr; curr= curr->next){
            push_back(curr->value);
        }
    }

};