#include <chrono>
#include <iostream>
#include <regex>
#include <stack>
#include <stdexcept>

// Definition for a Node.
class Node {
public:
    int val;
    Node(int _va,Node* _prev=nullptr,Node* _next=nullptr,Node* _child =nullptr) : val(_va), prev(_prev), next(_next), child(_child) {}

    Node* prev;
    Node* next;
    Node* child;
    void print(){
        std::cout << val << " ";
        if(next) next->print();
        else std::cout << "\n";}
};

Node* flatten(Node* head) {
    if(head == nullptr) return nullptr;
    std::stack<Node*> stack;
    Node* curr = head;
    while(curr){

        if(curr->child){
            stack.push(curr);
            curr = curr->child;
        }else{
            curr = curr->next;
        }


        if(curr && !curr->next && !stack.empty())
        {
            Node* top = stack.top();
            stack.pop();
            Node* next = top->next;
            
            top->next = top->child;
            top->child = nullptr;
            top->next->prev = top;

            curr->next = next;
            if(next) next->prev = curr;
        }
    }

    return head;

}

int main(){


    Node* first = new Node(1);

    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);


    first->next = second;
    second->child = third;
    second->next = fourth;

    flatten(first);
    first->print();

    return 0;
}