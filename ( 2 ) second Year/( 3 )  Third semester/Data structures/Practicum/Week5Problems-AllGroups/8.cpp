#include <iostream>
template <class T>
class Node {
public:
    T value;  // Стойност, съхранена във възела.
    Node<T>* next; // Указател към евентуалния следващ елемент.

    Node(T value = T(), Node* next = nullptr)
      : value(value), next(next)
    { }
    
    
};
template<class T>
void print(Node<T> *list){
    if(list == nullptr) {std::cout << "nullptr \n";}
    while(list != nullptr){
        std::cout << list->value << ' ';
        list =list->next;
    }
    std::cout << '\n';
}

template<class T>
Node<T>* mirror(Node<T>* &input){
    Node<T>* buffer = nullptr;
    
    Node<T>* curr = input;

    Node<T>* prev;

    while(curr){
        buffer = new Node<T>(curr->value, buffer);
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = buffer;

    return input;
}


int main(){

    Node<int> *first = new Node<int>(1, new Node(2, new Node(3)));
    
    mirror(first);

    print(first);



    return 0;
}