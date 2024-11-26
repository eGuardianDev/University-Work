#include "node.hpp"


template<class T>
void printLeftParentRight(const Node<T>* btree){
    if(!btree) return;

    if(btree->left) printLeftParentRight(btree->left);
    std::cout << btree->value << " ";
    if(btree->right) printLeftParentRight(btree->right);
}


int main(){

    Node<int> *btree = new Node<int>(1,
                               new Node<int>(2,
                                              new Node<int>(3),
                                              new Node<int>(4)),
                               new Node<int>(5,
                                              new Node<int>(6),
                                              new Node<int>(7)));
    printLeftParentRight(btree);
    deallocate(btree);

    return 0;
}