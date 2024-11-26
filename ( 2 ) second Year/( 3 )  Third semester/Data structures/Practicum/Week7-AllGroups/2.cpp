#include "node.hpp"

template<class T>
std::size_t findNodesNumber(Node<T> *btree){
    std::size_t size = 0;

    if(!btree) return 0;

    ++size;
    size +=findNodesNumber(btree->left);
    size +=findNodesNumber(btree->right);

    return size;


}
int main(){

    Node<int> *btree = new Node<int>(1,
                                new Node<int>(2,
                                            new Node<int>(3),
                                            new Node<int>(4)),
                                new Node<int>(5,
                                            new Node<int>(6),
                                            new Node<int>(7)));

    std::cout << findNodesNumber(btree) << "\n";


}