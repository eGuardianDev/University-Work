#include <iostream>

struct Node{
    int val;
    Node* next;
};

void print(Node* temp){
    if(!temp) {std::cout << '\n'; return;} 
    std::cout << temp-> val << " ";
    print(temp->next);
}
int main(){

    Node temp;
    Node *tail = &temp;

    tail->next = new Node{4};
    tail = tail->next;
    tail->next = new Node{2};

    print(temp.next);
    

    return 0;
}