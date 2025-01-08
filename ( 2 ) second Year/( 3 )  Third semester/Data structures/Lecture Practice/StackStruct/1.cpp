#include <iostream>


struct Node{
    int val = 0;
    Node* next = nullptr;

    Node* push(int val){
        Node* res = new Node{val, this };
        return res;
    }

    void Destruct(){
        if(next) next->Destruct();
        delete this;
    }    
};

void Destruct(Node* &node){
    if(node->next) node->next->Destruct();
    node->Destruct();
    node = nullptr;
}

// void push(Node* &node, int val){
//     node = new Node{val, node};
// }
void print(Node* node){
    if(node == nullptr) { std::cout << std::endl; return;}
    std::cout << node->val << " ";
    print(node->next);
}

int main(){

    Node* tos = nullptr;
    tos = tos->push(1);
    tos = tos->push(3);

    print(tos);

    tos->Destruct();
    return 0;
}