
#ifndef _Trie_hpp__
#define _Trie_hpp__

#include "wordStruct.hpp"
#include <cassert>
#include <iostream>
#include <vector>
const int COUNT_ALPHABET = 26;

class Trie{
private:
    struct Node;

public:

    Trie(){root = new Node();}
    ~Trie(){if(root){root->Destruct();}}

    void print() {
        std::vector<Word> res;
        getWordsNode(root,"", res);
        for(Word word : res){
            std::cout << word.data <<" "<<word.val <<" " <<word.count <<'\n';
        }        
    }
    std::vector<Word> getWords() {
        std::vector<Word> res;
        getWordsNode(root,"", res);
        return res;
    }

    void append(char* word, int val = 1, bool count = true) {
        appendNode(root, word, val, count);
    }
   
    int contains(char* word){
        return containsNode(root, word);
    }

    void foundedOne(char* word){
        int val = contains(word);
        if(val == -1){
            append(word, 1);
        }else{
            append(word, val);
        }
    }

private:
    Node* root;

    int containsNode(Node* node, char* word){
        assert(node != nullptr || word != nullptr);

        int index = int(*word -'a');

        if(node->isEndWord){
            return node->grade;
        }
        if(node->next[index]){
            return containsNode(node->next[index], word+1);
        }
        
        return -1;
        
    }
    void getWordsNode(Node* node, std::string word, std::vector<Word>& res){
        if(!node) return;
        if(node->isEndWord){

            res.push_back(Word{word.data(),node->grade, node->count});
        }
        for(int i =0 ;i<COUNT_ALPHABET;++i){
            if(node->next[i]){                
                getWordsNode(node->next[i], (word + char(i+'a')),res);
            }
        }
    }
   
    bool appendNode(Node* node, char* word, int& val,bool count = true){
        assert(node != nullptr || word != nullptr);

        if(*word == '\0')
        {
            if(node->grade == -1){
                node->grade = val;
            }
            node->isEndWord = true;
            // std::cout << count;
            if(count){
                
                node->count+=1;
            }else{
                node->count =0;
            }
            return true;
        } 

        int index = *word - 'a';

        if(!node->next[index]){
            node->next[index] = new Node;
        }
        appendNode(node->next[index], word+1, val,count);

        return true;
    }

    struct Node{
        Node* next[COUNT_ALPHABET] = {0};
        int grade = -1;
        int count = 0;
        bool isEndWord = false; 

        void Destruct(){
            for(int i =0; i<COUNT_ALPHABET;++i){
                if(next[i]){
                    next[i]->Destruct();
                }
            }
            delete this;
        }
    };

};

#endif // _Trie_hpp__