#include <iostream>

#include <fstream>
#include <ostream>
#include <stdexcept>

struct Node{
    int val = 0;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int val =0 ): val(val), left(nullptr), right(nullptr){}
    ~Node(){}
    void Desturct(){
        if(left) left->Desturct();
        if(right) right->Desturct();
        delete this;
    }
};

int getNumber(const char* data){
    int num= 0;
    int rot = 1;
 
    for(int i =0 ;i<255;++i){
        if(data[i] !='\0'){
            if(i == 0 && data[i] == '-'){
                rot = -1;
            }else{
                num *=10;
                num+=data[i]-'0';
            }
        }
        else{
            break;
        }
    }
    return rot * num;

}

bool isNumber(const char* data){
    for(int i =0 ;i<255;++i){
        if(data[i] !='\0'){
            if(i == 0 && data[i] == '-'){
                continue;
            }
            if(data[i]-'0' < 0 || data[i] -'0' >9)
            {
                return false;
            }
        }
        else{
            break;
        }
    }
    return true;

}


Node* readTree(std::istream& stm,int level = 0){
    Node* curr = nullptr;
    char val[255];
    while(stm >> val)
    {
        if(isNumber(val)){
            std::cout<< level << std::endl;;
            curr = new Node(getNumber(val));
            curr->left = readTree(stm, level+1);
            curr->right = readTree(stm,level+1);
        }
        else if(val[0] == 'x'){
            return nullptr;
        }else if(val[0] == '('){
            continue;
        }else if (val[0] == ')'){
            return curr;
        }
    }
    return curr;
}

Node* readTreeFromFile(const char* path){

    std::ifstream file(path);

    if(!file.is_open()){
        throw std::logic_error("No file found");
    }

    Node* root = nullptr;
    root = readTree(file);

    file.close();

    return root;
}

void outputTree(Node* tree, std::ostream& str){

    if(tree){
        
        str << "( "<< tree->val <<" ";
        outputTree(tree->left, str);
        outputTree(tree->right, str);
        str << ") ";
    }else{
        str << "x ";
    }
}

void outputTree(Node* tree, const char* path){
    if(!tree) throw std::invalid_argument("Empty tree, cannot be serialized");
    std::ofstream file(path);
    
    if(!file.is_open()){
        throw std::logic_error("Cannot open file");
    }


    outputTree(tree,file);
    file.close();

}

void printSpaces(int n){
    for (int i =0; i<n;++i){
        std::cout << " "; 
    }
}

void printTree(Node* root, int tabs =0){
    if(tabs ==0){
        std::cout << "Printing tree: "<<std::endl;
    }
    if(!root) return;

    if(root->left) printTree(root->left, tabs+1);
    printSpaces(tabs);
    std::cout << root->val << std::endl;
    if(root->right) printTree(root->right, tabs+1);
}


int main(){


    Node* tree = readTreeFromFile("input.txt");

    // printTree(tree);

    outputTree(tree,std::cout);
    tree->Desturct();

    return 0;
}