#include <iostream>



struct Node{
    int val =0;
    Node* next = nullptr;
    Node(int val, Node* next = nullptr) : val(val), next(next){
    }
    ~Node(){}
    void destruct(){
        if(next) next->destruct();
        delete this;
    }

};

void trying(Node*& a){
    if(a) a = a->next;
}
void print(Node* a){
    if(a){
        std::cout << a->val << " ";
        print(a->next);
    }
}

int main(){

    Node* head = new Node(1, new Node(2, new Node (3, new Node (4))));

    Node* curr = head->next;
    trying(head->next);
    print(head);

    return 0;
}