#include <iostream>

template <class T>
class Node {
public:
    T value;  // Стойност, съхранена във възела.
    Node<T>* next; // Указател към евентуалния следващ елемент.

    Node(T value = T(), Node* next = nullptr)
      : value(value), next(next)
    { }
    
    
};
template<class T>
void print(Node<T> *list){
    if(list == nullptr) {std::cout << "nullptr \n";}
    while(list != nullptr){
        std::cout << list->value << ' ';
        list =list->next;
    }
    std::cout << '\n';
}


//! try inline
inline int getDigit(Node<int>* node){
    if(node == nullptr) return 0;
    else return node->value;
}
inline void moveNext(Node<int>* &node){
    if(node == nullptr) return;

    Node<int>* temp = node;
    node = node->next;
    delete temp;

}

Node<int> *sumNodes(Node<int>* first, Node<int>* second){

    Node<int>* linkedSum = nullptr;
    int carry = 0;
    while(first != nullptr || second != nullptr || carry != 0){
        int val1 = getDigit(first);
        int val2 = getDigit(second);
        int sum = val1+val2 + carry;
        carry = 0;
        if(sum > 9){
            ++carry;
            sum-=10;
        }
        linkedSum = new Node(sum, linkedSum);
        
        moveNext(first);
        moveNext(second);

    }

    return linkedSum;
}

int main(){
    //this is the number in reverse
    //we are giving  2 1
    // and second is 9 2
    Node<int> *first = new Node<int>(1, new Node(2));
    Node<int> *second = new Node<int>(2, new Node(9));

    Node<int>* sum = sumNodes(first, second);

    print(sum);
    return 0;
}