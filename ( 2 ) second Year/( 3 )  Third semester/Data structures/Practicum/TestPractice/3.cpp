#include <cassert>
#include <climits>
#include <endian.h>
#include <iostream>
#include <stdexcept>

struct ListNode{
    int val = 0;
    ListNode* next = nullptr;
    void Destruct(){
        if(next) next->Destruct();
        delete this;
    }
    
    int& get(size_t index){
        ListNode* val = this;
        while(index >0){
            if(!val) throw std::overflow_error("Out of bound"); 
            val = val->next;
            --index;
        }
        return val->val;
    }
    void push_back(const int val){
        ListNode* temp = this;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new ListNode{val};
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


bool contains(ListNode* visited, int val){
    //skip first because its empty
    visited = visited->next;
    while(visited){
        if(visited->val == val){
            return true;
        }
        visited = visited->next;
    }
    return false;
}
bool isSet(TreeNode* node, ListNode* visited){
    if(!node) return true;

    if(contains(visited, node->val)){
        return false;
    }

    visited->push_back(node->val);
    
    return isSet(node->left, visited) && isSet(node->right,visited);
}

bool isSet(TreeNode* node){
    ListNode* visited = new ListNode;
    return isSet(node,visited);

}

void listFromTree(TreeNode* node, ListNode* list){
    if(node == nullptr) return;
    
    listFromTree(node->left, list);
    if(node->left){
        list = list->next;
    }
    list->next = new ListNode {node->val};
    list = list->next;
    listFromTree(node->right, list);
}
ListNode* listFromTree(TreeNode* node){
    ListNode* list = new ListNode;
    listFromTree(node, list);
    // fix list 
    ListNode* temp = list;
    list = list->next;
    delete temp;

    return list;
}

TreeNode* TreeFromList(ListNode* list, int l, int r){
    if(l> r) return nullptr;

    int mid = (l + r )/2;
    
    return new TreeNode{list->get(mid), TreeFromList(list, l, mid-1), TreeFromList(list, mid+1, r)};
    
}

TreeNode* TreeFromList(ListNode* list){
    int size =0;
    ListNode* temp = list;
    while(temp){
        ++size;
        temp = temp->next;
    }

    return TreeFromList(list, 0,size-1);
}

void print(TreeNode* tree, int tab = 0){
    if(!tree) return;

    print(tree->left, tab+1);
    std::cout << std::string(tab, ' ') << tree->val << '\n';
    print(tree->right, tab+1);
}
void print(ListNode* node){
    if(!node) {std::cout << std::endl; return;}
    std::cout << node->val << ' ';
    print(node->next);
}

void appendNode(TreeNode* &node, int val){ 
    if(node == nullptr){
        node = new TreeNode{val};
        return;
    }
    if(node->val < val){
        appendNode(node->right, val);
    }else {
        appendNode(node->left, val);
    }
}

void copyTree(TreeNode*& copy, TreeNode* other){
    if(other == nullptr) return;
    copy = new TreeNode{other->val};
    copyTree(copy->left, other->left);
    copyTree(copy->right, other->right);
}

int countOfNodes(TreeNode* node){
    if(!node) return 0;
    return 1+countOfNodes(node->left)+countOfNodes(node->right); 
}
void addToTree(TreeNode* &tree, TreeNode* other){
    if(other == nullptr) return;
    appendNode(tree, other->val);
    addToTree(tree, other->left);
    addToTree(tree, other->right);
}
TreeNode* Union(TreeNode* t1, TreeNode* t2){

    TreeNode* newTree;
    int count = countOfNodes(t2);
    copyTree(newTree, t1);

    addToTree(newTree, t2);

    return newTree;
}



int main(){
    TreeNode* root = TreeFromList(new ListNode{1,new ListNode{2, new ListNode{3, new ListNode{4}}}});
    TreeNode* root2 = TreeFromList(new ListNode{3,new ListNode {4, new ListNode {5, new ListNode {6, new ListNode{7}}}}});


    print(Union(root,root2));


    // std::cout << isBST(root)<< isSet(root);
    // root->Destruct();
    // root2->Destruct();
    // temp->Destruct();
    return 0;
}