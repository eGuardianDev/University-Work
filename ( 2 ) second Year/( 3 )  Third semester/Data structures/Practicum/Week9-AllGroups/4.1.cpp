
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
            toCreate.push(curr->left);
            toCreate.push(curr->right);

        }else{
            res += "=";
        }
        
        // std::cout << curr->left;

    }

        
    return res;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(std::string data) {

    if(data == "") return nullptr;
    int ch =0;
    std::queue<int> vals;

    for(int  j = 0;j<data.length();++j){
        if(data[j] == ' '){
            vals.push(ch);
            ch = -1;
        }
        else if(data[j] == '='){
            vals.push(-1);
        }
        else{
            if(ch == -1) ch = 0;
            ch *=10;
            ch += data[j] - '0';
        }
    }
    if(ch >=0){
        vals.push(ch);
    }

    std::queue<TreeNode*> nodes;
    TreeNode* head;
    if(!vals.empty())
    {
        int val = vals.front(); vals.pop();
        head = new TreeNode(val);
        nodes.push(head);
    }
    while(!vals.empty())
    {
        TreeNode* curr = nodes.front(); nodes.pop();
        int val = vals.front(); vals.pop();
        if(val != -1){
            curr->left = new TreeNode(val);
            nodes.push(curr->left);
        }
        if(vals.empty())break;
      
        val = vals.front(); vals.pop();
        
        if(val != -1){
            curr->right = new TreeNode(val);
            nodes.push(curr->right);
        }
    }

    return head;
    return nullptr;
}

void print(TreeNode* a){
    if(!a) {
        std::cout << "empty tree\n";
        return;
    }

    if(a->left) print(a->left);
    std::cout << a->val;
    if(a->right) print(a->right);

}

int main(){

    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    a->left = b;
    a->right = c;
    std::string in =serialize(a);

    // std::cout << serialize(a);

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