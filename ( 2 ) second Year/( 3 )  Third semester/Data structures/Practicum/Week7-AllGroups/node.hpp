#ifndef _SINGLE_LINKED_NODE_HPP_
#define _SINGLE_LINKED_NODE_HPP_

#include <iostream>

template <class T>
class Node
{
    public:
        T value;
        Node<T> *left, *right;

        Node(T value = T(), Node *left = nullptr, Node *right = nullptr)
            : value(value), left(left), right(right) {}

        void print() const 
        {
            if (this == nullptr) { return;}

                
            std::cout << value << " ";
            if(left)  left->print();
            if(right) right->print();

        }
};

template <typename T>
void deallocate(Node<T>* head)
{
    if(!head) return;

    Node<T>* temp = head;
    deallocate(temp->left);
    deallocate(temp->right);
    delete temp;
    return;
}

#endif