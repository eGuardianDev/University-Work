#include <iostream>
#include <vector>
#include <fstream>

struct node{
    int val=0;
    std::vector<node*> children;
    node(int val= 0) : val(val) , children(std::vector<node*>(0)) {}

    void destruct(){
        for(int i= 0;i<children.size();++i){
            if(children[i]){
                children[i]->destruct();
            }
        }
        delete this;
    }
};


std::vector<std::string> split(std::string data){
    std::vector<std::string> res;
    bool first = true;
    
    std::string num;
    for(int i =0;i<data.size();++i){
        if(data[i] == '|'){
            if(first){
                first = false;
                continue;
            }
            if(num.size() > 0){

                res.push_back(num);
                num = "";
            }
            res.push_back("|");
        }else if(data[i] == ' '){
            if(num.size() > 0){
                res.push_back(num);
                num = "";
            }
            continue;
        }else{
            num += data[i];
        }

    }


    return res;
}

node* readTree(std::string path){
    std::fstream file(path);
    if(!file.is_open()){
        std::cout << "Cannot open\n";
        return nullptr;
    }
    
    std::string data;
    int index= 0;
    std::vector<node*> nodes;
    node dummy;
    node* root =& dummy;
    nodes.push_back(root);
    while(std::getline(file,data)){
        for(std::string a : split(data)){
            if(a == "|"){
                ++index;
            }else{
                node* temp = new node(stoi(a));
                nodes[index]->children.push_back(temp);
                nodes.push_back(temp);
            }
        }

    };
    file.close();

    return dummy.children[0];
}
void print(node *root, int tabs =0){
    std::cout << std::string(tabs, ' ')  << root->val  <<  '\n';
    
    for(int i = 0;i <root->children.size();++i){
        print(root->children[i], tabs+1);
    }
}
int main(){
    node *temp = readTree("test3.txt");
    print(temp);

    temp->destruct();
    return 0;
}