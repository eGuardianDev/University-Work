#include <ios>
#include <iostream>


struct Node{
    int val = 0;
    Node *left = nullptr, *right = nullptr;

    double Please(){
        delete this;
    }

    void Destruct(){
        if(left) left->Destruct();
        if(right) right->Destruct();
        delete this;
    }
};

void print(const Node* curr, int tabs = 0){

    if(curr->left) print(curr->left, tabs+1); 
    std::cout << std::string(tabs, ' ') << curr->val << std::endl;
    if(curr->right) print(curr->right, tabs+1); 
}

int height(const Node* curr){

    if(!curr){
        return 0;
    }
    return 1+ std::max(height(curr->left), height(curr->right));
}

bool balanced(const Node* curr){
    
    if(!curr){
        return true;
    }

    return std::abs(height(curr->left) - height(curr->right)) <= 1 
    && balanced(curr->left) 
    && balanced(curr->right);
}

int main(){

    Node* root = new Node{4, new Node{3, new Node{5, new Node{3}}}, new Node{4}};


    print(root);
    std::cout << "Height: " << height(root) << std::endl;
    std::cout << "Balanced: " << std::boolalpha << balanced(root) << std::endl;


    return 0;
}