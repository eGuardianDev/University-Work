#include <iostream>
#include <string>
#include <vector>


class N_Tree{
public:

    
    struct Node{
        
        std::string name;
        bool isFile;
        int Size;

        std::vector<Node*> childrens;

        Node(std::string _name,bool _isFile = false,int _size =0) : name(_name), isFile(_isFile), Size(_size) {}
        ~Node(){}

        void clean(){
            for(int i =0;i<childrens.size();++i){
                childrens[i]->clean();
                delete childrens[i];
            }
        }

        int size(){
            if(!isFile){
                int count =0;
                for(int i =0;i<childrens.size();++i){
                    count += childrens[i]->size();
                }
                return count;
            }
            std::cout << name << " "<< Size << "\n";
            
            return Size;
        }

        std::string print(){
            return ( name + " ("  + std::to_string(Size) + ")"); 
        }
    };
private:
    Node* root;

public:

    N_Tree(std::string default_name) : root(new Node(default_name, false)){}
    ~N_Tree(){root->clean(); delete root;}

    void print(Node* curr = nullptr, int _tabs = 0){
        if(curr == nullptr) curr = root;

        std::cout << std::string(_tabs, '\t') << curr->print() << '\n';
        
        for(Node* child : curr->childrens){
            print(child, _tabs+1);
        }
    }

    Node* findFolder(std::vector<std::string> data, bool generateFlag = false){
        Node* curr = root;
          if(curr->name != data[0]){
            return nullptr;
        }

        for(int i =1 ;i<data.size()-1;++i){
            for(Node* child : curr->childrens){
                if(child->name == data[i]){
                    if(child->isFile) return nullptr;
                    curr = child;
                    break;
                }
            }
            if(generateFlag == true){
                Node* temp = new Node(data[i], false);
                curr->childrens.push_back(temp);
                curr = temp;
                continue;
            }else return nullptr;
            
        }
        return curr;
    }

    bool generate(std::vector<std::string> data, bool generateFlag = false, int size =0){
        
        Node* curr = findFolder(data,generateFlag);

        if(!curr) return false;

        for(Node* child : curr->childrens){
            if(child->name == data[data.size()-1]) return false;
        }
        curr->childrens.push_back(new Node(data[data.size()-1], true,size));
        return true;
    }
    

    bool remove(std::vector<std::string> data){
        Node* curr;
        std::string last ;
        if(data.size() >1){
            last = data[data.size()-1];
            data.pop_back();
            curr = findFolder(data);
        }else return false;
        if(!curr) return false;
        for(int i =0; i< curr->childrens.size(); ++i ){
            Node* child = curr->childrens[i];
            if(child->name == last){
                std::string response;
                std::cout << "are you sure you want to delete " << (child->isFile ? "file ": "folder " )<< child->name << "? ";
                std::getline(std::cin, response);
                if(response == "yes") 
                {
                    std::cout << "deleted " << child->name <<"\n" ;
                    child->clean();
                    curr->childrens.erase(std::next(curr->childrens.begin(),i));
                    delete child;
                }
                else std::cout << "Not deleted\n";
             
            }
        }
        return false;
    }

    void printSizes(std::vector<std::string> data, int _tabs = 0){
        Node* curr = root;
        if(data.size() != 0) curr = findFolder(data);
        int a =curr->size();
        std::cout << curr->name << "/ " <<a << '\n';
        
    }
};



std::vector<std::string> Split(std::string data, char cut = ' '){
    std::vector<std::string> toReturn;
    int i =0;
    toReturn.push_back("");
    for(char a : data){
        if(a == cut){
            toReturn.push_back("");
            ++i;
            continue;
        }
        toReturn[i] += a;
    }
    return toReturn;
} 

enum Commands{
    cmd_invalid = -1,
    cmd_exit = 0,
    cmd_save = 1,
    cmd_print = 2,
    cmd_size = 3,
    cmd_remove = 4
};

Commands CommandTranslate(std::string data){
    if(data == "exit") return cmd_exit;
    if(data == "save") return cmd_save;
    if(data == "print") return cmd_print;
    if(data == "size") return cmd_size;
    if(data == "delete") return cmd_remove;
    return cmd_invalid;
}


int main(){

    N_Tree tree = N_Tree("main");
    std::string cmd;
    for(;;){
        std::getline(std::cin, cmd);
        std::vector<std::string> output;
        if(cmd.length() >0){
            output = Split(cmd);
            cmd = output[0];
        }
        bool generateFlag = false;
        
        std::vector<std::string> args;

        if(output.size() >=3 && output[3] == "-c") generateFlag = true; 
        if(output.size() >=2)  args = Split(output[1], '/');


        switch(CommandTranslate(cmd)){
            
            case cmd_exit:
                std::cout << "exitting program\n";
                break;

            case cmd_remove:
                if(tree.remove(args)) std::cout << "deleted succesful\n";
                else std::cout << "Something failed\n";
                break;
            case cmd_size:
                
                tree.printSizes(args);
                break;
            case cmd_print:
                tree.print();
                break;
            case cmd_save:
                std::cout << "saving data\n";
                if(output.size() <3){
                    std::cout << "expected 2 argument\n";
                    break;
                }
                    if(tree.generate(args,generateFlag, stoi(output[2]))) std::cout << "Created a file\n";
                    else std::cout << "Couldn't find file\n";
                
                break;
            case cmd_invalid:
                std::cout << "invalid command\n";
                break;
        }
        args.clear();
        output.clear();
        generateFlag = false;

    }


    return 0;
}