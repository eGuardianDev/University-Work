#include "0.h"


template<class T>
void removeConsecutiveDuplicates(Node<T>* lst){
    Node<T> * curr = lst;

    while(curr != nullptr){

        if(curr->prev != nullptr){

            if(curr->prev->value == curr->value){

                Node<T>* temp = curr;
                curr = curr->next;

                temp->prev->next = temp->next;
                
                if(temp->next != nullptr){
                    temp->next->prev = temp->prev;
                }
                temp->next = temp->prev = nullptr;
                delete temp;

                continue;
            }
        }
        curr = curr->next;
    }

    
}

int main(){


    Node<int> * t1 = new Node<int>(1);
    Node<int> * t2 = new Node<int>(1);
    Node<int> * t3 = new Node<int>(2);

    t1->next = t2;
    
    t2->prev = t1; t2->next = t3;

    t3->prev = t2;


    t1->print();
    removeConsecutiveDuplicates(t1);
    t1->print();

    return 0;
}