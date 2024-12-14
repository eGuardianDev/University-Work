#include <iostream>



struct Node{
    int val = 0;
    Node *left = nullptr,
         *right= nullptr;

} * head;

void print(Node *root, int steps = 0){
    if(!root) 
    {
        std::cout <<  std::string(steps,' ')<< '-'<< "\n";
        return;
    }
    print(root->left, steps+1);
    std::cout << std::string(steps,' ') <<root->val << std::endl;
    print(root->right,steps+1);

}

void remove(Node* &ref){
    Node* temp = ref;
    ref = ref->right;
    delete temp;
}


void collapse(Node* root){
    if(!root) return;
    collapse(root->left);
    collapse(root->right);
    delete root;
}

int main(){

    head = new Node{ 0, nullptr, new Node{1, nullptr, new Node{2}}};

    print(head);

    remove(head->right);
    print(head);
    collapse(head);
    

    return 0;
}