
#ifndef _Trie_hpp__
#define _Trie_hpp__

#include "./wordStruct.hpp"
#include <cassert>
#include <iostream>
#include <new>
#include <vector>
const int COUNT_ALPHABET = 26;

class Trie{
private:
    struct Node;

public:

    Trie(){root = new Node();}
    ~Trie(){if(root){root->Destruct();}}

    void print() const;
    std::vector<Word> getWords() const;

    void append(char* word, int val = 1, bool count = true);
    const bool contains(char* word) const;
    const Word getWord(char* word);

private:
    Node* root;

    Word getWordHelper(Node* root, char* word,std::string& curr) const;

    const bool containsHelper(Node* node, char* word) const;
   
    void getWordsHelper(Node* node, std::string word, std::vector<Word>& res) const;
   
    void appendHelper(Node* node, char* word, int& val,bool count = true);

    struct Node{
        Node* next[COUNT_ALPHABET] = {0};
        int grade = 1;
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