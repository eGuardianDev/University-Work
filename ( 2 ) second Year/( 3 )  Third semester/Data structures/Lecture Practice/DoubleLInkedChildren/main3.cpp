#include <iostream>
#include <stack>


struct Node{
    
    int val;
};

void runtemp(std::stack<Node*>& a){

    Node* temp = new Node {1};
    a.push(temp);
    std::cout << temp << '\n';
    std::cout << &temp << '\n';
}

int main(){
    std::stack<Node*> stack;

    runtemp(stack);
    std::cout << stack.top();
}