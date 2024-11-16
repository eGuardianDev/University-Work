#include <iostream>
class Node {
public:
    Node(int val) : val(val){
        prev= nullptr;
        next = nullptr;
        child = nullptr;
    }
    int val;
    Node* prev;
    Node* next;
    Node* child;

    void print(){
        std::cout << val;
        if(next != nullptr){
            std::cout << " <-> ";
            next->print();
            if(child) child->print();
            return;
        }
        std::cout << std::endl;
    }
};

Node* flatten(Node* head) {

    Node* curr = head;

    while(curr != nullptr){
        
        if(curr->child)// != nullptr
        {
            Node* oldNext = curr->next;

            curr->next = curr->child;
            curr->next->prev = curr;
            curr->child = nullptr;
            flatten(curr->next);
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = oldNext;
            if(oldNext != nullptr){
                oldNext->prev= curr;
            }
        }
        curr = curr->next;
    } 

    return head;
}


int main(){
    
   

    Node* t1 = new Node(1);
    Node* t2 = new Node(2);
    Node* t3 = new Node(3);
    t1->next =t2;

    t2->prev = t1;
    t2->next =t3;
    
    t3->prev = t2;
    
    
    Node* t1_1 = new Node(4);
    Node* t1_2 = new Node(5);

    t1_1->next = t1_2;
    t1_2->prev = t1_1;


    t2->child = t1_1;

    t1->print();

    flatten(t1);

    t1->print();

    return 0;
}