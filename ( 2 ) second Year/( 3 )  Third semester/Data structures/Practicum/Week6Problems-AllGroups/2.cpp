#include "0.h"


template<class T>
void reverse(Node<T>* &lst){
    
    Node<T> *prev;
    while(lst != nullptr)
    {
        prev = lst;
        Node<T>* temp = lst->next;
        lst->next = lst->prev;
        lst->prev = temp;
        lst = temp;
    }
    lst = prev;
}   

template<class T>
void mirror(Node<T>* lst){

    Node<T> *curr = lst;

    Node<T>* mirrored;

    while(curr->next != nullptr){
        
        //init
        if(mirrored == nullptr){
            mirrored = new Node<T>(curr->value);
            curr = curr->next;
            continue; 
        }

        //add
        mirrored->add(curr->value);
        curr = curr->next;

    }

    mirrored->add(curr->value);
    reverse(mirrored);
    curr->next = mirrored;
    
    // curr->print();
    // prev->print();
    // prev->next = prevMirrored;
    // prevMirrored->prev = prev;
}

int main(){

    Node<int> * t1 = new Node<int>(1);
    Node<int> * t2 = new Node<int>(1);
    Node<int> * t3 = new Node<int>(2);

    t1->next = t2;
    
    t2->prev = t1; t2->next = t3;

    t3->prev = t2;


    t1->print();
    mirror(t1);
    t1->print();

    return 0;
}