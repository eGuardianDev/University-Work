

#include <fstream>
#include <iostream>
#include <stack>
#include <stdexcept>
struct  Node{
    int val = 0;
    Node *left =nullptr, *right = nullptr;

    void Destruct(){
        if(left) left->Destruct();
        if(right) right->Destruct();
        delete this;
    }
};



int getNumber(const char* data){

    int number = 0;
    int res = 1;
    for(int i =0;i<255;++i){
        if(data[i] == '\0'){
            break;
        }else{
            
            if(i == 0&& data [i] == '-'){
                res= -1;
            }else{
                int num = data[i]-'0';
                number *= 10;
                number += num;
            }
            
        }
    }
    return number * res;
}


bool isNumber(const char* data){

    for(int i =0;i<255;++i){
        if(data[i] == '\0'){
            break;}
            if(i == 0 && data [i] == '-'){
                continue;
            }
            
            int num = data[i]-'0';

            if(num<0 || num >9){
                return false;
            }
        
    }
    return true;
}
void serialize(std::fstream &file, Node*& curr) {
    std::string data;
    file >> data;

    std::cout << "Read data: " << data << std::endl;  // Debug output

    if (data.empty()) return;  // Handle empty input gracefully

    switch (data[0]) {
        case '(':
            curr = new Node;                // Create a new node
            serialize(file, curr);          // Deserialize current node
            serialize(file, curr->left);    // Deserialize left child
            serialize(file, curr->right);   // Deserialize right child
            file >> data;
            if(data != ")"){
                throw std::invalid_argument("FUCK YOU");
            }
            break;
        case 'x':
            curr = nullptr;  // Null node
            break;
        case ')':
            break;  // Close the current recursion level

        default:
            if (isNumber(data.data())) {
                curr->val = getNumber(data.data());  // Assign value to the current node
            } else {
                throw std::invalid_argument("Invalid data encountered: " + data);
            }
            break;
    }
}
Node* serialize(const char* path){
    std::fstream file(path);

    if(!file.is_open()){
        throw std::invalid_argument("Invalid file/path");
    }
    
    Node* root;
    serialize(file, root);
    return root;
}


void print(Node* tree,int tabs =0){
    if(!tree) return;
    if(tree->left) print(tree->left, tabs+1); 
    std::cout << std::string(tabs, ' ')  << tree->val << std::endl;
    if(tree->right) print(tree->right,tabs +1); 
}
int main()
{
    print(serialize("input.txt"));
    return 0;
}