



#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string sort(std::string input){
    for(int i =0 ;i<input.size();++i){
        for(int j =i+1; j<input.size();++j){
            if(input[i] > input[j]){
                std::swap(input[i],input[j]);
            }
        }
    }

    return input;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    
    std::unordered_map<std::string, std::vector<std::string>> map;

    std::string key = "";
    for(int i =0;i <strs.size();++i){
        key = sort(strs[i]);
        map[key].push_back(strs[i]);
    }
    
    std::vector<std::vector<std::string>> res;
    for(auto a : map){
        std::vector<std::string> temp;
        for(auto b : a.second){
            temp.push_back(b);
        }
        res.push_back(temp);
    }
    return res;
}

int main(){

    std::cout << "a\n";

    std::vector<std::string> strs ={"eat","tea","tan","ate","nat","bat"};


    for(std::vector<std::string> a :groupAnagrams(strs)){
        std::cout << "[\n";
        for(std::string str : a){
            std::cout << str << " ";
        }
        std::cout << "]\n";
    }


    return 0;
}