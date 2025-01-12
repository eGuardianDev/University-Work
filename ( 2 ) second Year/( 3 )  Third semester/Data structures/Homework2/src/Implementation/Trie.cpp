
#include "../header/Trie.hpp"
#include <cstring>
#include <new>
#include <stdexcept>

// == public == 

void Trie::print() const{
    std::vector<Word> res;
    getWordsHelper(root,"", res);
    for(Word word : res){
        std::cout << word.data << " " << word.val << " " <<word.count <<'\n';
    }        
}

std::vector<Word> Trie::getWords()const{
    std::vector<Word> res;
    getWordsHelper(root,"", res);
    return res;
}

void Trie::append(char* word, int val, bool count) {
    if(root == nullptr){ 
        root = new Node;
    }
    appendHelper(root, word, val, count);
}

const bool Trie::contains(char* word) const {
    return containsHelper(root, word);
}
const Word Trie::getWord(char* word) {
    std::string res(word);
    return getWordHelper(root, word, res);
}


// == private ==

Word Trie::getWordHelper(Node* node, char* word, std::string& toRet) const{
    assert(node != nullptr || word != nullptr);

    int index = int(*word -'a');

    if(node->isEndWord){
        return Word{toRet,node->grade,node->count};
    }
    if(node->next[index]){
        return getWordHelper(node->next[index], word+1, toRet);
    }
    
    throw std::logic_error("Word doesn't exist");
}

const bool Trie::containsHelper(Node* node, char* word) const {
    assert(node != nullptr || word != nullptr);

    int index = int(*word -'a');

    if(node->isEndWord){
        return true;
    }
    if(node->next[index]){
        return containsHelper(node->next[index], word+1);
    }
    
    return false;
    
}
void Trie::getWordsHelper(Node* node, std::string word, std::vector<Word>& res) const{
    if(!node) return;
    if(node->isEndWord){

        res.push_back(Word{word.data(),node->grade, node->count});
    }
    for(int i =0 ;i<COUNT_ALPHABET;++i){
        if(node->next[i]){                
            getWordsHelper(node->next[i], (word + char(i+'a')),res);
        }
    }
}

void Trie::appendHelper(Node* node, char* word, int& val, bool count){
    assert(node != nullptr || word != nullptr);
    if(*word == '\0')
    {
        node->isEndWord = true;
        if(count){
            node->count+=1;
        }else{
            node->grade = val;
            node->count =0;
        }
        return;
    } 

    int index = *word - 'a';

    bool alreadyExist = false;
    if(!node->next[index]){
        node->next[index] = new Node;
        
    } else alreadyExist = true;
    
    try{
        appendHelper(node->next[index], word+1, val,count);
    }catch(std::bad_alloc& e){
        if(!alreadyExist){
            delete node->next[index];
            node->next[index] = nullptr;
        }
        throw e;
    }

    return;
}
