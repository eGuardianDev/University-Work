#include "tree.hpp"
#include <cmath>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>

//ex1

// bool isBinaryTree(T_Node* tree){
//     if(!tree) return true;
//     if(tree->left && tree->left->val > tree->val) return false;
//     if(tree->right && tree->right->val < tree->val) return false;
//     return isBinaryTree(tree->left) && isBinaryTree(tree->right);
// }

bool isBinaryTree(T_Node* tree, int prev){
    if(!tree) return true;

    if(tree->left)
    {
        if(tree->left->val > tree->val) return false;
        else if(tree->left->val > prev) return false;

    } 
    if(tree->right)
    {
        if(tree->right->val < tree->val) return false;
        else if(tree->right->val > prev) return false;
    }

    int v = tree->val;
    
    return isBinaryTree(tree->left, v) && isBinaryTree(tree->right, v);
}

//ex2

int height(T_Node* tree){
    if(!tree) return 0;
    
    int v1 = height(tree->left);
    int v2 = height(tree->right);

    return std::max(v1,v2)+1;
}

bool isBalanced(T_Node* tree){
    if(!tree) return true;


    int left = height(tree->left);
    int right = height(tree->right);

    if(std::abs(left-right)<=1 && isBalanced(tree->left) && isBalanced(tree->right)) return true;

    return false;
}

//ex 3
void treeToVector(std::vector<T_Node*>& vector, T_Node* tree){
    
    std::queue<T_Node*> que;
    
    que.push(tree);
    
    while(!que.empty())
    {
        T_Node* top = que.front(); que.pop();

        vector.push_back(top);
        
        if(top){
            que.push(top->left);
            que.push(top->right);
        }
    }
    
    return;
}

T_Node* vectorToTree(std::vector<int>& vector, int left =0, int right = -1){

    if(vector.size() == 0) return nullptr;
    if(right == -1) right = vector.size();

    if(left >= right) return nullptr;

    int mid = left+ (right-left)/2;
    std::cout << "getting " << mid << "\n";
    
    T_Node* tree = new T_Node(vector[mid]);

    T_Node* l = vectorToTree(vector, left,mid);
    T_Node* r = vectorToTree(vector, mid+1, right);

    tree->left = l;
    tree->right = r;

    return tree;
}

void printTree(T_Node* a){
    if(!a) return;

    printTree(a->left);
    std::cout << a->val;
    printTree(a->right);


}
int main(){
    // T_Node* tree = new T_Node(5, new T_Node(4,nullptr, new T_Node(7)),
    //                                  new T_Node(6,new T_Node(3),  
    //                                                         new T_Node(7)));
    

    std::vector<int> a = {1,2,3,4,5,6};
    T_Node* tree = vectorToTree(a);
    // printTree(tree);

    std::cout << std::boolalpha << isBinaryTree(tree, tree->val) << std::endl;
    
    std::vector<T_Node*> b;
    treeToVector(b,tree);

    for(T_Node* ch: b){
        if(ch) std::cout << ch->val << " ";
        else   std::cout << "null" << " ";
    }
    // std::cout << std::endl;


    // T_Node* loadTree;
    // std::vector<int> a = {1,2,3,4};

    // loadTree = vectorToTree(a);

    // treeToVector(b, loadTree);

    // for(T_Node* ch: b){
    //     if(ch) std::cout << ch->val << " ";
    //     else   std::cout << "null" << " ";
    // }
    // std::cout << std::endl;
    
    return 0;
}