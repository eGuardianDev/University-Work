#include "header/Trie.hpp"
#include "header/kheap.hpp"
#include "header/wordStruct.hpp"
#include <iostream>
#include <fstream>
#include <new>
#include <stdexcept>
#include <vector>

void readDictionary(Trie& tree, const std::string& path ){

    std::ifstream File;
    File.open(path);

    if(!File.is_open())
    {
        throw std::invalid_argument("File \"" + path+ "\" doesn't exist");
    }

    std::string data;
    while(File >> data)
    {
        std::string word = data;
        File >> data;
        for(int i =0;i<word.size();++i){
            word[i] = tolower(word[i]);
        }

        int val = 0;
        try{
            val = stoi(data);
        }catch(std::invalid_argument e){
            throw std::invalid_argument("The passed grade of word is bad (probably not an Int)");
        }
        try{
            tree.append(word.data(), val, false);
        }catch(std::bad_alloc& e){
            std::cout << data << " wasn't added due to bad_alloc" << std::endl;
        }
    }
    File.close();
}


std::string formatWord(std::string word){
    
    assert(word.size() > 0);

    for(int i =0;i<word.size();++i){
       word[i] = tolower(word[i]);
    }

    bool removeEnd = false;
    bool removeStart = false;
    if(word.size()>1){
        switch(word[word.size()-1]){
            case '.':
            case ',':
            case '!':
            case ':':
            case '\'':
            case '\"': 
            removeEnd = true;
            break;
        }
    }
    switch(word[0]){
        case '\'':
        case '\"': 
        removeStart = true;
        break;
    }

    std::string res = "";
    for(int i =0; i<word.size();++i){
        if(i ==0 && removeStart) {
            continue;
        }
        if(i ==word.size()-1 && removeEnd){
            continue;
        }
        res += word[i];
    }
    return res;
} 

void readFromText(Trie &tree, std::string& path){
    std::ifstream File;
    File.open(path);

    if(!File.is_open())
    {
        throw std::invalid_argument("File \"" + path+ "\" doesn't exist");
    }

    std::string data;
    while(File >> data)
    {
        try{
            tree.append(formatWord(data).data());
        }catch(std::bad_alloc& e){
            std::cout << data << " wasn't added due to bad_alloc" << std::endl;
        }
    }

    File.close();
}

int main(){
    Trie tree;

    std::string pathToDictinary;
    std::cout << "Name of Dictinary file: ";
    std::cin >> pathToDictinary;
    readDictionary(tree, pathToDictinary);

    int heapK;
    std::cout << "k-heap - size of k: ";
    std::cin >> heapK;
    
    kHeap heap(heapK);
   

    std::string pathToText;
    std::cout << "Name of text file: ";
    std::cin >> pathToText;
    readFromText(tree, pathToText);

    std::vector<Word> words = tree.getWords();
    for(int i =0 ;i< words.size();++i){

        words[i].val *= words[i].count;
    }

    try{
        heap.buildFromVector(words, true);
    }catch(std::bad_alloc& e){
        std::cout << "Failed building from vector - bad alloc - " << e.what() << std::endl;
    }


    int displayElements;
    std::cout << "Count of elements to display (M): ";
    std::cin >> displayElements;

    words.clear();
    
    int longestWord = 0;
    while(displayElements >0 && !heap.isEmpty()){
        Word w = heap.extractMin();
        longestWord = longestWord > w.data.length()? longestWord : w.data.length();
        words.push_back(w);
        --displayElements;
    }


    std::cout << " Words" << std::string( std::max(0, longestWord-5),' ') << "| Count | val" << std::endl;
    for(int i =0;i<words.size();++i){
        Word w = words[i];
        std::cout <<" "<< w.data <<std::string( std::max(0, int(longestWord-w.data.length())), ' ') << "| " << w.count << " | " << w.val<<"\n";
    }

    if(displayElements > 0){
        std::cout <<"Couldn't display " <<  displayElements<< " words, because the text doesn't have enought"  << std::endl;
    }
}