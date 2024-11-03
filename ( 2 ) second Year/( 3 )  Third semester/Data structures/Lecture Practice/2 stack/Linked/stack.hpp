

#ifndef _STACK_HEADER__
#define _STACK_HEADER__

template<class DataType>
class LinkedStack{

public:

    LinkedStack<DataType>();
    ~LinkedStack<DataType>();

    LinkedStack<DataType>(const LinkedStack<DataType>& other);
    LinkedStack<DataType>& operator=(const LinkedStack<DataType>& other);   

    void push(const DataType& element);
    void pop();

    bool isEmpty() const {return tos == nullptr;}
    const DataType& top() const {return tos->data;}


private:
    struct node{
        DataType data;
        node* next;

        node(const DataType& input, node* _next) : data(input) { next = _next;}
    };


    void copy(const node* n);
    void clear();

    node *tos;
};

#include "stack.inl"

#endif //_STACK_HEADER__