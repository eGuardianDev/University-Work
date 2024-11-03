

#ifndef _Linked_stack_implementation__
#define _Linked_stack_implementation__


#include <stdexcept>
template<class DataType>
LinkedStack<DataType>::LinkedStack() : tos(nullptr) {}
template<class DataType>
LinkedStack<DataType>::~LinkedStack(){
    clear();
}

template<class DataType>
void LinkedStack<DataType>::clear(){
    if(tos == nullptr) return;

    node* temp = tos;
    while(temp != nullptr){
        node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    tos = nullptr;
}
template<class DataType>
void LinkedStack<DataType>::copy(const node* top){
    if(top){
        clear();
        node* current = new node(top->data, nullptr);
        node* next = top->next;
        tos = current;
        while(next != nullptr){
            current->next = new node(next->data, nullptr);
            next = next->next;
        }
    }
}

template<class DataType>
LinkedStack<DataType>::LinkedStack(const LinkedStack<DataType>& other){
    operator=(other);
}

template<class DataType>
LinkedStack<DataType>& LinkedStack<DataType>::operator=(const LinkedStack<DataType>& other){
    if(this != &other){
        copy(other.tos);
    }
    return *this;
}  

template<class DataType>
void LinkedStack<DataType>::push(const DataType& element){
    tos = new node(element, tos);
}
template<class DataType>
void LinkedStack<DataType>::pop(){
    if(tos == nullptr){
        throw std::underflow_error("trying to pop empty stack");
    }
    node* temp = tos->next;
    delete tos;
    tos = temp;
}




#endif //_Linked_stack_implementation__