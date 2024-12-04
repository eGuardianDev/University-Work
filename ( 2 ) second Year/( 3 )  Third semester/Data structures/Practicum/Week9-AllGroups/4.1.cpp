
// Definition for a binary tree node.
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

        
    return res;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(std::string data) {
    
}

int main(){

    return 0 ;
}



// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;