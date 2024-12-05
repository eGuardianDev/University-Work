#include <iostream>
#include <vector>

class BST{
struct Node;




public:
    BST(int* input, std::size_t size){
        root = makeTree(input,size);
    }

private:
    Node* makeTree(int* arr, std::size_t size ){
        int half = size/2;
        Node * mid 
        
        Node *result = new Node(
            arr[size/2],
            makeTree(arr,size/2),
            makeTree(arr + size/2, size/2));

        return nullptr;
    }

private:
    struct Node{
        int val;
        Node* left =nullptr;
        Node* right = nullptr;
        Node(int _val, Node* _left, Node* _right ) : val(_val), left(_left), right(_right){}
        ~Node(){}
    };
    
    Node* root;

};

int main(){


    return 0;
}