#include <iostream>
#include "tree.hpp"



void print(T_Node* root, int steps =0){
    if(!root) return; 

    print(root->left, steps+1);
    std::cout << std::string(steps, ' ' )<< root->val <<'\n';
    print(root->right,steps+1);
}

int main(){

    T_Node* tree = new T_Node(2, new T_Node(1), new T_Node(3));

    print(tree);


    return 0;
}