
#include "../header/Trie.hpp"
#include <cstring>
#include <stdexcept>

// == public == 

void Trie::print() const{
    std::vector<Word> res;
    getWordsNode(root,"", res);
    for(Word word : res){
        std::cout << word.data << " " << word.val << " " <<word.count <<'\n';
    }        
}

std::vector<Word> Trie::getWords()const{
    std::vector<Word> res;
    getWordsNode(root,"", res);
    return res;
}

void Trie::append(char* word, int val, bool count) {
    appendNode(root, word, val, count);
}

const bool Trie::contains(char* word) const {
    return containsNode(root, word);
}
const Word Trie::getWord(char* word) {
    std::string res(word);
    return getWordNode(root, word, res);
}


// == private ==
Word Trie::getWordNode(Node* node, char* word, std::string& toRet) const{
    assert(node != nullptr || word != nullptr);

    int index = int(*word -'a');

    if(node->isEndWord){
        return Word{toRet,node->grade,node->count};
    }
    if(node->next[index]){
        return getWordNode(node->next[index], word+1, toRet);
    }
    
    throw std::logic_error("Word doesn't exist");
}

const bool Trie::containsNode(Node* node, char* word) const {
    assert(node != nullptr || word != nullptr);

    int index = int(*word -'a');

    if(node->isEndWord){
        return true;
    }
    if(node->next[index]){
        return containsNode(node->next[index], word+1);
    }
    
    return false;
    
}
void Trie::getWordsNode(Node* node, std::string word, std::vector<Word>& res) const{
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

void Trie::appendNode(Node* node, char* word, int& val,bool count){
    assert(node != nullptr || word != nullptr);

    if(*word == '\0')
    {
        if(node->grade == -1){
            node->grade = val;
        }
        node->isEndWord = true;
        if(count){
            
            node->count+=1;
        }else{
            node->count =0;
        }
        return;
    } 

    int index = *word - 'a';

    if(!node->next[index]){
        node->next[index] = new Node;
    }
    appendNode(node->next[index], word+1, val,count);

    return;
}
