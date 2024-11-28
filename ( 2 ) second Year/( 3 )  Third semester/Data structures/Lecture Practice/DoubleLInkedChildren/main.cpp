#include <iostream>
#include <regex>
#include <stack>
#include <stdexcept>

struct Node{

    Node(int val = 0, Node* _next = nullptr, Node* _child =nullptr  ) : value(val), next(_next), child(_child){}
    ~Node(){}

    void Clean(){
        if(next) next->Clean();
        if(child) child->Clean();
        delete this;
    }
    void print(){
        std::cout << value << " ";
        if(next) next->print();
        else std::cout << "\n";
    }
    int value;
    Node * next;
    Node * child;

};

void FixStack(std::stack<Node*>& stack){
    if(stack.empty()) throw std::invalid_argument("empty stack");
    Node* curr = stack.top(); stack.pop();
    while(!stack.empty()){
        stack.top()->next = curr;
        curr->child = nullptr;
        curr = stack.top();
        stack.pop();
    }
    curr->child = nullptr;
    
    // while(!stack.empty()){
    //     std::cout << stack.top()->value;
    //     stack.pop();
    // }
}


Node* FlattenIN(Node* head, std::stack<Node*>& stack){
    if(!head) return nullptr;
    Node* curr = head;
    while(curr != nullptr){
        stack.push(curr); // !  problem with push ?? &
        if(curr->child) FlattenIN(curr->child, stack);
        curr = curr->next;
    }
    return head;
}

Node* Flatten(Node* head){
    std::stack<Node*> st;
    Node* temp = FlattenIN(head,st);

    FixStack(st);
    return temp;
}

int main(){

    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    first->next = second;
    second->child = third;
    second->next = fourth;

    Flatten(first);
    first->print();

    return 0;
}