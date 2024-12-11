#include <cstddef>
#include <ios>
#include <iostream>


struct TrieNode{

    TrieNode* children[26];
    bool isFinal;

    TrieNode()
     : isFinal(false){
        for(int i =0;i<26;++i){
            children[i] = nullptr;
        }
    }

    ~TrieNode(){
        
    }


};

void deallocate(TrieNode* root){
    
    if(!root) return;

    for(std::size_t i =0 ;i<26;++i){
        deallocate(root->children[i]);
        
    }
    delete root;
}


void addWord(TrieNode* root,const char* word){
    std::size_t it = 0;
    while(word[it] != '\0'){

        std::size_t index = word[it] - 'a'; 
        
        if(!root->children[index])
            root->children[index] = new TrieNode();

        root = root->children[index];   
        ++it;
    }
    root->isFinal = true;
}

void printWords(TrieNode* root, const std::string& currWord){
    if(root == nullptr) return;

    if(root->isFinal) std::cout << currWord << "\n";

    for(std::size_t i = 0; i<26;++i){
        if(root->children[i]){
            printWords(root->children[i], currWord + char('a'+ i));
        }
    }
}

TrieNode* traverseTrieTo(TrieNode* root, const std::string& prefix){

    std::size_t it = 0;
    while(prefix[it] != '\0'){
        std::size_t index = prefix[it] -'a';
        
        if(!root->children[index]) return nullptr;
    
        root = root->children[index];
        ++it;
    }

    return root;
}

void autoComplete(TrieNode* root, const std::string& prefix){
    if(!root) return;

    root = traverseTrieTo(root, prefix);
    if(!root) std::cout << "error\n";
    printWords(root, prefix);
   
}

bool contains(TrieNode* root, const std::string& word){
    TrieNode* temp = traverseTrieTo(root, word);
    return temp;
}

int hasChildren(TrieNode*& root){
    int count = 0;
    for(std::size_t i =0 ;i<26;++i){
        if(root->children[i]) ++count;
    }
    return count;
}

bool removeWord(TrieNode* root, const char* word){
    
    if(!root) return false;
    
    if(*word == '\0') return true;

    bool flag = removeWord(root->children[*word-'a'],word+1);

    if(!flag) return false;

    deallocate(root->children[*word-'a']);
    root->children[*word-'a'] = nullptr;

    if(root->isFinal || hasChildren(root) > 0) return false;
    
    return true;
}


int main(){

    TrieNode* root = new TrieNode();

    addWord(root, "aa");
    addWord(root, "abb");
    addWord(root, "abbc");
    addWord(root, "abbd");

    printWords(root,"");
    
    std::cout << " before del \n";
    autoComplete(root, "a");
   

    removeWord(root, "abbd");
    std::cout << " after del \n";


    printWords(root, "");

    deallocate(root);

    return 0;
}