
#include <fstream>
#include <ios>
#include <iostream>

//binary search tree
class Tree{
    struct Node;

    public:

    Tree(){
        root = nullptr;
    }
    ~Tree(){
        if(root) root->destruct();
    }

    const int Size() const { return size; }

    const int height() const {
        return height(root);
    }
    const int weight() const {
        return weight(root);
    }

    bool balanced(){
        return balanced(root);
    }
    bool perfectBalanced(){
        return perfectBalanced(root);
    }

    void append(int val){
        append_helper(root, val);
    }
    bool search(int val){
        return search_helper(root,val);
    }

    bool remove(int val){
        if(!search(val)) return false;
        remove_helper(root, val);
        return true;
    }

    std::ostream& print(std::ostream & stream){
        print_helper(root, stream);
        return stream;
    }

    private:
    void append_helper(Node*&curr, int val){
        if(curr == nullptr){
            ++size;
            curr = new Node{val};
        }else{
            if(curr->val < val){
                append_helper(curr->right, val);
            }else{
                append_helper(curr->left, val);
            }
        }
    }
    bool search_helper(Node*&curr,int val){
        if(curr == nullptr) return false;
        else if (curr->val == val) return true;
        else{
            if(curr->val < val) return search_helper(curr->right, val);
            else return search_helper(curr->left, val);
        }
    }

    void print_helper(Node* &curr, std::ostream& stream, int tabs =0){
        if(curr == nullptr) return;
        
        print_helper(curr->left,stream, tabs+1);
        stream << std::string(tabs, ' ') <<curr->val << std::endl;
        print_helper(curr->right,stream,tabs+1);
    }

    int height (const Node* curr)const{
        if(!curr) return 0;
        return 1 + std::max(height(curr->left), height(curr->right));
    }
    int weight(const Node * curr) const{
        if(!curr) return 0;
        return 1 + weight(curr->left) + weight(curr->right);
    }

    bool balanced(Node*& curr) const
    {
        return std::abs(height(curr->left) - height(curr->right)) <=1 && balanced( curr->left) && balanced(curr->right);
    }

    bool perfectBalanced(Node* & curr) const
    {
        if(!curr) return true;
        return std::abs(weight(curr->left) - weight(curr->right)) <=1 && perfectBalanced( curr->left) && perfectBalanced(curr->right);
    }

   
    Node* getMin(Node* &curr){
        if(curr->left){
            return getMin(curr->left);
        }
        Node* toRet = curr;
        curr = curr->right;
        return toRet;
    }
    void remove_helper(Node* &curr, int val){
        if(curr == nullptr) return;

        if(curr->val < val) remove_helper(curr->right, val);
        else if(curr->val > val) remove_helper(curr->left, val);
        else{

            
            Node* toDelete = curr;
            if ( !curr->right){
                curr = curr->left;
            }else if (!curr->left){
                curr = curr->right;
            }else{
                Node* extracted = getMin(curr->right);
                extracted->left = curr->left;
                extracted->right = curr->right;
                curr = extracted;
            }  
            --size;
            delete toDelete;
        }
    }


    private:

    Node* root;
    int size = 0;
    struct Node{
        int val;
        Node *left = nullptr, * right = nullptr;

        void destruct(){
            int val =0;
            if(left)left->destruct();
            if(right)right->destruct();
            delete this;
        }
    };
    
};


int main(){

    Tree tree;

    tree.append(3);
    tree.append(10);
    tree.append(1);
    tree.append(2);

    tree.print(std::cout);

    std::cout << std::boolalpha;
    std::cout << "Found 10: " <<tree.search(10) <<std::endl;
    std::cout << "Found 5: " <<tree.search(5) <<std::endl;
    

    tree.remove(1);
    tree.print(std::cout);
    
    return 0;
}