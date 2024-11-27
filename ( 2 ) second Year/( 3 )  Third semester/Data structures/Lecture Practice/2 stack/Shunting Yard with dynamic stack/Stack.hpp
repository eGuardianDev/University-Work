

#ifndef _STACK_HPP
#define _STACK_HPP

template <class T>
struct Node{
    T value;
    Node* next;

    Node(T _val = 0, Node* _next = nullptr ) : value(_val), next(_next) {}
    ~Node(){       
    }

    void clean(){
        if(next) next->clean();
        delete this;

    }

};

template <class T>
class Stack{
public:

Stack() : tos(nullptr){}
~Stack() {if(tos)tos->clean();}

Stack(Stack& other);
Stack& operator=(Stack& other);

// Stack(Stack&& other);
// Stack& operator=(Stack&& other);



void push(const T& data);

void pop();

const T& top() const;

bool empty() const;


private:
    void copy(Node<T>* other);
    void clear();
    Node<T> * tos; 
};

#include "Stack.inl"

#endif