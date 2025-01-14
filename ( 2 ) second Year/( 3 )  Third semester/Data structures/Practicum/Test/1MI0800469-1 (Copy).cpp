#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

struct Node{
    int val;
    std::vector<Node> children;
    Node(int val) : val(val) { }
    bool addElement(const int val){
        for(Node child : children){
            if(child.val == val){
                return false;       
            }
        }
        // std::cout << "Adding " << val << " to "<< this->val << '\n';
        children.push_back(Node(val));
        return true;
    }
};

void print(Node node, int steps = 0){
    std::cout << std::string(steps, ' ') << node.val << std::endl;
    for(Node child : node.children){
        print(child, steps+1);
    } 
}

std::vector<std::string> splitString(std::string data ){
    std::vector<std::string> res;
    std::string curr; 
    for(int i =0; i< data.size(); ++i){
        if(data[i] == ' '){
            if(curr.size() >0){
                res.push_back(curr);
                curr = "";
            }
            continue;
        }
        if(data[i] == '|'){
            res.push_back("|");
            curr = "";
            continue;
        }
        curr += data[i];
    }
    return res;
}

int stringToInt(std::string data){
    int val =0;
    for(int i =0 ;i< data.size();++i){
        if(data[i] >='0' && data[i] <='9'){
            val *= 10;
            val += data[i]- '0';
        }else{
            throw std::invalid_argument("Trying to parse non digit to Int");
        }
    }
    return val;
}

Node generateTreeFromFile(Node &root, std::string path = "1.txt"){
    
    std::fstream File(path);

    if(!File.is_open()){
        throw std::invalid_argument("file doesn't exist");
    }

    std::string data;
    
    std::vector<Node> list;
    list.push_back(root);

    int index = 0;
    
    char* str = new char[255];

    std::vector <std::string> finals;
    bool ignoreFirst = true;
    while(!File.eof())
    {
        data = "";
        ignoreFirst = true;
        File.getline(str, 255); // <- took a while to figure out this
        data = str;
        
        std::vector<std::string> res = splitString(data);
      
        
        int child = 0;
        for(int i =0; i<res.size();++i){
            if(res[i] != "|"){
                list[index].addElement(stringToInt(res[i])); // <- it says it adds, but it doesn't?!?
                list.push_back(list[index].children[child++]);
            }else{
                if(!ignoreFirst){
                    ++index;
                }else{
                    ignoreFirst = false;
                }
            }
        }
    }
    delete str;
    // return root.children[0];  // <- this should be the correct one
    return root;
}
bool contains(std::vector<Node> list, Node curr){
    for(int i =0; i<list.size();++i){
        if(list[i].val == curr.val){
            return true;
        }
    }
    return false;
}

bool startContains(Node t1, Node t2){
    if(t1.val == t2.val){

        if(t2.children.size() == 0){
            return true;
        }else{

            bool flag = true;
            for(int i =0;i<t2.children.size();++i){
                if(!contains(t1.children, t2.children[i])){
                    flag = false;
                }
            }
            if(!flag) return false;

            
            for(int i =0; i<t2.children.size();++i){
                for(int j =0;j<t1.children.size();++j){
                    if(t2.children[i].val == t1.children[j].val){
                        if(!startContains(t1.children[j], t2.children[i])){
                            return false;
                        }
                    }
                }
            }
            return true;
        }

    }
    return false;

}


bool contains(Node t1, Node t2){
    if(t1.val == t2.val){
        if(startContains(t1, t2)){
            return true;
        }    
    }

    for(int i =0 ;i<t1.children.size();++i){
        if(contains(t1.children[i], t2)){
            return true;
        }
    }
    return false;
}

int main(){
    // not complete and throws bad alloc
 Node root4(0);
   generateTreeFromFile(root4);
   print(root4);

    Node root(1);
    root.addElement(2);
    root.addElement(3);
    root.children[1].addElement(4);
    root.children[1].addElement(5);
    root.children[1].children[1].addElement(6);
    root.addElement(4);

    Node root2(3);
    root2.addElement(5);
    root2.children[0].addElement(6);
 
    print(root);
    print(root2);
 
    std::cout << contains(root, root2);

    return 0;
}
