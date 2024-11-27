#include <stdexcept>
// #include "Stack.hpp"

template<class T>
inline void Stack<T>::push(const T& data){
    if(!tos) {
        tos = new Node<T>(data,nullptr);
    }else{
        Node<T> *temp = new Node<T>(data,tos);
        tos = temp;
    }
}

template<class T>
inline void Stack<T>:: pop(){
    if(!tos) throw std::underflow_error("Cannot pop empty stack");
    Node<T> *temp = tos;
    tos = tos->next;
    delete temp;
}


template<class T>
inline const T& Stack<T>::top() const{
    if(!tos) throw std::underflow_error("Cannot top empty stack");
    return tos->value;
}


template<class T>
inline bool Stack<T>::empty() const{
    return !tos;
}


template<class T>
inline void Stack<T>::copy(Node<T>* other){
    if(!other) tos = nullptr;

    tos = new Node(other->value);

    Node<T>* _tos = tos;

    Node<T>* current = other->next;

    while(current != nullptr){
        _tos->next = new Node(current->value);
        current = current->next;
        _tos = _tos->next;
    }

}


template<class T>
Stack<T>::Stack(Stack<T>& other){
    this->copy(other.tos);
}

template<class T>
Stack<T>& Stack<T>::operator=(Stack<T>& other){
    if(this != &other){
        clear();
        copy(other.tos);
    }
    return *this;
}

template<class T>
void Stack<T>::clear(){
    if(tos) tos->clean();
    tos = nullptr;
}



// Stack(Stack&& other){
//     swap(*this, other);
// }
// Stack& operator=(Stack&& other){
//     if(*this != other){
//         swap(*this, other);
//     }
// }


// template class Stack<int>;