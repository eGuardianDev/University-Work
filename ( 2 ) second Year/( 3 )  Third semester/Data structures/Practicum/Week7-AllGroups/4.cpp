#include "node.hpp"
#include <cmath>
#include <queue>
#include <vector>

template<class T>
void printLeftParentRight(const Node<T>* btree){
    if(!btree) return;

    if(btree->left) printLeftParentRight(btree->left);
    std::cout << btree->value << " ";
    if(btree->right) printLeftParentRight(btree->right);
}


Node<unsigned int>* generateBTree(unsigned int count){

    if(count == 0) return nullptr;
    Node<unsigned int>* tree = new Node<unsigned int>(1);
    Node<unsigned int>* curr;
    
    std::queue<Node<unsigned int>*> queue;
    
    int index = 1;
    queue.push(tree);

    while(index < count){
        curr = queue.front();
        queue.pop();

        curr->value = index++;
        if(index < count)curr->left = new Node<unsigned int>(index++);
        else break;
        if(index < count)curr->right = new Node<unsigned int>(index++);
        else break;
        queue.push(curr->left);
        queue.push(curr->right);

    }

    // while(!queue.empty()){
    //     if(queue.front()->value == 0){
    //         delete queue.front();
    //         queue.pop();
    //     }
    // }


    return tree;
}


int main(){

//9
Node<unsigned int> *btree = generateBTree(9);
printLeftParentRight(btree);
// std::cout << btree->left->value;

// Изход:
// 8 4 9 2 5 1 6 3 7
// т.е. зад btree стои дървото:
//      1
//     / \
//   2     3
//   /\    /\
//  4  5  6  7   
//  /\
// 8  9 

}