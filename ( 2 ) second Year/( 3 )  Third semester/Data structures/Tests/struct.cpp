#include <iostream>

struct Node{
    int val;
    Node* next = nullptr;
} *node =  new Node{15};
 

int main(){
    std::cout << node->val;


}