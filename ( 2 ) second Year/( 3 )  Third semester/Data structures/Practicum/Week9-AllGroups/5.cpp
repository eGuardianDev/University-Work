#include "tree.hpp"
#include <cfloat>
#include <ios>
#include <iostream>
#include <vector>

template <typename T>
class Set
{
public:
    virtual bool contains(const T& data) const = 0;
    virtual void add(const T& data) = 0;
    virtual void remove(const T& data) = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
};


class TreeSet : public Set<int>{

    T_Node* head = nullptr;
    int count = 0;
    public:


    bool contains(const int& data) const override{
        if(empty()) return false;
        T_Node* curr = head;
        while(curr){
            if(curr->val == data) return true;

            if(curr->val < data){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        return false;
    }
    void add(const int& data) override{

        if(contains(data)){
            return;
        }

        ++count;
    
        if(head == nullptr) {
            head = new T_Node(data);
            return;
        }
       
        T_Node* curr = head;

        while(curr){
            if(curr->val <=data){
                //left
                if(curr->left) curr = curr->left;
                else {
                    curr->left = new T_Node(data);
                    return;
                }
            }else{
                //right
                if(curr->right) curr = curr->right;
                else {
                    curr->right= new T_Node(data);
                    return;
                }
            }
        }
    }
    void remove(const int& data) override{ 
        if(contains(data)){
            remove_element(head, data);
        }

    }
    int size() const override{
        return count;
    }
    bool empty() const override{
        return head == nullptr;
    }

    void print()const{
       print_normal(head);
    }

    void buildTree(const std::vector<int>& a){
        buildTree(a,0,a.size());
    }

    void Clear(){
        head->Destruct();
        head = nullptr;
    }
    private:
    void buildTree(const std::vector<int>& a,int left, int right){
        

        


    }


    bool remove_element( T_Node*& root, const int& data){
        
        if(root == nullptr) return true;
        
        T_Node* toDelete = root;
        
        if(root->val == data){
            if(!root->left){
                root = root->right;
            }else if (!root->right){
                root = root->left;
            }else{
                T_Node* minR = getMin(root->right);

                minR->left = root->left;
                minR->right = root->right;
                root = minR;
            }


            --count;
            delete toDelete;
            return true;
        }else{
            return remove_element(root->val <= data ? root->left: root->right, data);
        }


        return false;
    }

    T_Node* getMin(T_Node*& root){
        if(root->left){
            return getMin(root->left);
        }

        T_Node* n = root;
        root = root->right;
        
        return n;

    }

    void print_helper(T_Node* curr)const{
        if(!curr) return;

        print_helper(curr->right);
        std::cout << curr->val<< " ";
        print_helper(curr->left);
    }
    void print_normal(T_Node* curr, int steps =0)const{
        if(!curr) return;

        std::cout << std::string(steps, ' ');
        std::cout << curr->val<< " \n";
        print_normal(curr->right,steps+1);
        print_normal(curr->left,steps+1);
    }

    

};

bool twoSum(const std::vector<int>& data, int target){
    TreeSet a;
    for(int num : data){
        bool b =a.contains(target-num);
        if(b) return b;
        a.add(num);
    }

    
    return false;
}

int countUniques(const std::vector<int>& data)
{
    TreeSet a;
    for(int num : data){
        a.add(num);
    }
    return a.size();
}

int main(){
    TreeSet a;

    // a.add(2);
    // a.add(5);
    // a.add(3);
    // a.add(4);
    // a.add(1);
    // a.add(0);
    // a.print();
    // std::cout << std::endl;
    // a.remove(5);
    // a.print();

    std::cout << countUniques({1,2,3,3,4});
    std::cout << twoSum({1,2,4,4,5}, 12);
    // std::cout << a.contains(2);
    // std::cout << a.contains(3);
    // a.add(3);
    // std::cout << a.contains(3);

    // std::cout << a.contains(1);

    // a.add(1);
    // std::cout << a.contains(1);
    return 0;
}