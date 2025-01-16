#include <climits>
#include <iostream>
#include <vector>

struct ListNode{
    int val =0;
    ListNode* next = nullptr;
    void Destruct(){
        if(next) next->Destruct();
        delete this;
    }
};
struct TreeNode{
    int val=0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    void Destruct(){
        if(left) left->Destruct();
        if(right) right->Destruct();
        delete this;
    }
};

int getMin(TreeNode* node){
    if(node == nullptr) return INT_MAX;
    int val = node->val;

    int min = std::min(val, getMin(node->left)); 
    min = std::min(min, getMin(node->right)); 
    return min;
}

int getMax(TreeNode* node){
    if(node == nullptr) return INT_MIN;
    int val = node->val;

    int max = std::max(val, getMax(node->left)); 
    max = std::max(max, getMax(node->right)); 
    return max;
}

bool isBST(TreeNode* node){
    if(node == nullptr) return true;

    if(node->left && getMax(node->left) > node->val){
        return false;
    }
    if(node->right && node->val >= getMin(node->right) ){
        return false;
    }

    return isBST(node->left) && isBST(node->right);
}


bool contains(std::vector<int>& visited, int val){
    for(int i =0;i<visited.size();++i){
        if(visited[i] == val){
            return true;
        }
    }

    return false;
}
bool isSet(TreeNode* node, std::vector<int>& visited){
    if(!node) return true;

    if(contains(visited, node->val)){
        return false;
    }

    visited.push_back(node->val);
    
    return isSet(node->left, visited) && isSet(node->right,visited);
}

bool isSet(TreeNode* node){
    std::vector<int> visited;
    return isSet(node,visited);
}

void vectorFromTree(TreeNode* node, std::vector<int>& vector){
    if(node == nullptr) return;

    vectorFromTree(node->left, vector);
    vector.push_back(node->val);
    vectorFromTree(node->right, vector);
}
std::vector<int> vectorFromTree(TreeNode* node){
    std::vector<int> vector;
    vectorFromTree(node, vector);
    return vector;
}

TreeNode* TreeFromVector(std::vector<int> vector, int l, int r){
    if(l> r) return nullptr;

    int mid = (l + r )/2;
    
    return new TreeNode{vector[mid], TreeFromVector(vector, l, mid-1), TreeFromVector(vector, mid+1, r)};
    
}

TreeNode* TreeFromVector(std::vector<int> vector){
    return TreeFromVector(vector, 0, vector.size()-1);
}

TreeNode* Union(TreeNode* t1, TreeNode* t2){

    std::vector<int> v1 = vectorFromTree(t1);
    std::vector<int> v2 = vectorFromTree(t2);
  
    std::vector<int> output;

    auto it1 = v1.begin();
    auto it2 = v2.begin();
    while(output.size() < v1.size() + v2.size())    
    {
        if(it1 != v1.end() && *it1 < *it2 ){
            output.push_back(*it1++);
        }else if(it2 == v2.end()){
            output.push_back(*it1++);
        }
        else{
            output.push_back(*it2++);
        }
    }

    std::cout << std::endl;
    
    return TreeFromVector(output);
}

TreeNode* intersention(TreeNode* t1, TreeNode* t2){

    std::vector<int> v1 = vectorFromTree(t1);
    std::vector<int> v2 = vectorFromTree(t2);
  
    std::vector<int> output;

    auto it1 = v1.begin();
    auto it2 = v2.begin();
    while(output.size() < v1.size() + v2.size())    
    {
        if(it1 != v1.end() && it2 != v2.end()){
            if(*it1 > *it2){
                ++it2;
            }else if(*it1 < *it2){
                ++it1;
            }else{
                output.push_back(*it1);
                ++it1;
                ++it2;
            }

        }else{
            break;
        }
        
    }

    std::cout << std::endl;
    
    return TreeFromVector(output);
}

TreeNode* Diffrence(TreeNode* t1, TreeNode* t2){


    std::vector<int> v1 = vectorFromTree(t1);
    std::vector<int> v2 = vectorFromTree(t2);
  
    std::vector<int> output;

    auto it1 = v1.begin();
    auto it2 = v2.begin();
    while(it1 != v1.end() || it2 != v2.end())    
    {
        if(it1 == v1.end()){
            output.push_back(*it2++);
        }else if(it2 == v2.end()){
            output.push_back(*it1++);
        }else{
            if(*it1 < *it2 ){
            output.push_back(*it1++);
            }else if(*it1 > *it2 ){
            output.push_back(*it2++);
            }else{
                ++it1; ++it2;
            }
        }
    }

    std::cout << std::endl;
    
    return TreeFromVector(output);
}
void print(TreeNode* tree, int tab = 0){
    if(!tree) return;

    print(tree->left, tab+1);
    std::cout << std::string(tab, ' ') << tree->val << '\n';
    print(tree->right, tab+1);
}

int main(){
    TreeNode* root = TreeFromVector({1,2,3,4});
    TreeNode* root2 = TreeFromVector({3,4,5,6,7});

    TreeNode* temp = Union(root,root2);
    print(temp);

    std::cout << isBST(temp)<< isSet(temp);
    root->Destruct();
    root2->Destruct();
    temp->Destruct();
    return 0;
}