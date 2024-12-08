
// Definition for a binary tree node.
#include <iostream>
#include <queue>
#include <string>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 

// Encodes a tree to a single string.
std::string serialize(TreeNode* root) {
    std::string res;
    if(!root) return res;

    
    std::queue<TreeNode*> toCreate;

    toCreate.push(root);
    TreeNode* curr;

    while(!toCreate.empty()){
        curr = toCreate.front(); toCreate.pop();

        if(curr != nullptr){
            res+=std::to_string(curr->val) + " ";
        }else{
            res += "=";
        }
        
        toCreate.push(curr->left);
        toCreate.push(curr->right);

    }

    // std::cout << res << std::endl;
        
    return res;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(std::string data) {

    int num = 0;
    bool more = false;
    std::queue<int> a;
    std::queue<TreeNode*> tree;
    TreeNode* root;
    tree.push(root);
    for(char ch : data){

        if(ch == '='){  
            TreeNode* curr = tree.front(); 
            tree.pop();
            curr = nullptr;
        }
        else if(ch != ' '){
            num*=10;
            num+=ch-'0';
            more = true;
        }else{

            TreeNode* curr = tree.front(); 
            curr = new TreeNode(num);
            tree.pop();
            tree.push(curr->left);
            tree.push(curr->right);
            num = 0;
            more = false;
        }
    }

   
    return root;
}

void print(TreeNode* a){
    if(!a) {
        std::cout << "empty tree\n";
    }

    if(a->left) print(a->left);
    std::cout << a->val;
    if(a->right) print(a->right);

}

int main(){

    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    a->left = b; a->right = c;
    // std::string in =serialize(a);


    TreeNode* out = deserialize("1 2 3");

    print(out);

    return 0 ;
}



// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;