#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Trie.hpp"
#include "kheap.hpp"
#include "wordStruct.hpp"

std::string formatWord(std::string word){

    for(int i =0;i<word.size();++i){
       word[i] = tolower(word[i]);
    }

    bool removeEnd = false;
    bool removeStart = false;
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

void readWords(Trie &t, std::string path = "words.txt"){
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
        t.append(word.data(), val, false);
    }

    File.close();
}

void readText(Trie &t, std::string path = "words.txt"){
    std::ifstream File;
    File.open(path);

    if(!File.is_open())
    {
        throw std::invalid_argument("File \"" + path+ "\" doesn't exist");
    }

    std::string data;
    while(File >> data)
    {
        std::cout << data << " " << formatWord(data) << "\n";
        t.append(formatWord(data).data());
    }

    File.close();
}



int main(){

    Trie t;
    readWords(t);

    std::vector<Word> temp = t.getWords();
    std::cout << "Words read\n";

    for(auto a: temp){
        std::cout << a.data << a.val << a.count << '\n';
    }

    readText(t, "randomText.txt");
    std::cout << "In text:\n";
     temp = t.getWords();

    for(auto a: temp){
        std::cout << a.data << " " << a.val<<" " << a.count << '\n';
    }

    std::cout << "Transforming words\n";

    kHeap heap;
    for(auto a: temp){
        a.val = a.count *a.val;
        heap.insert(a);
    }

    std::cout << "How many you like (M): ";
    int m =0;
    std::cin >> m;
    std::cout << "Word | Count | Value" << std::endl;
    while(m >0 && !heap.isEmpty()){
        Word w = heap.extractMin();

        std::cout << w.data << " | " << w.count << " | " << w.val << std::endl;
        --m;
    }
    if(m>0){
        std::cout << "Not enought words in the text";
    }


    // t.print();

    // std::string dat = "asd";

    // char *a = new char[dat.size()];
    // a[dat.size()] = '\0';
    // std::copy(dat.begin(),dat.end(),a);
    // dat = "2";

    // std::cout << a;
    // heap.insert("cat", 3);
    // heap.insert("dog", 5);
    // heap.insert("fish", 2);
    // heap.insert("rat", 15);

    // std::cout << heap.extractMin().data;
    // std::cout << heap.extractMin().data;
    // std::cout << heap.extractMin().data;
    // std::cout << heap.extractMin().data;

    return 0;
}