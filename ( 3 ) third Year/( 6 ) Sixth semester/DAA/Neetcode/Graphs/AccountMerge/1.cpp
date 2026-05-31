#include <algorithm>
#include <functional>
#include <iostream>

#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string,vector<int>> graph;

    for(int i =0;i<accounts.size();++i){
        for(int j =1;j <accounts[i].size();++j){
            graph[accounts[i][j]].push_back(i);
        }
    }

    // for(auto & [a,b] : graph){
    //     cout << a << " : ";
    //     for(auto c : b){
    //         cout << c << " ";
    //     }cout <<endl;
    // }


    unordered_map<int,int> ranks; // node -> rank; // node -> parent_node
    
    for(int i =0;i<accounts.size();++i){
        ranks[i] = i;
    }

    // for(auto& [key, val] : graph ){
    //     int max_rank = -1;
    //     for(auto node : val ){
    //         max_rank = max(max_rank, ranks[node]);
    //     }
    //     for(auto node : val ){
    //         ranks[node] = max_rank;
    //     }
    // }
    function<int(int)> find = [&](int x) -> int {
        if (ranks[x] != x)
            ranks[x] = find(ranks[x]);  // path compression, same map you already had
        return ranks[x];
    };
    for(auto& [key, val] : graph){
        for(int i = 1; i < val.size(); ++i)
            ranks[find(val[0])] = find(val[i]);  // unite instead of max
    }


    unordered_map<int, vector<string>> mappings;

    for(auto& [key, val] : graph){
        int parent = ranks[val[0]];
        mappings[parent].push_back(key);
    }

    vector<vector<string>> strs;
    for(auto& [key, vals]:mappings){
        vector<string> row = vals;      // copy the vector<string>
        sort(row.begin(), row.end());
        row.insert(row.begin(), accounts[key][0]);  // add key at front
        strs.push_back(std::move(row));

    }




    return strs;
}

int main(){

    vector<vector<string>> in ={     
    {"neet","neet@gmail.com","neet_dsa@gmail.com"},
    {"alice","alice@gmail.com"},
    {"neet","bob@gmail.com","neet@gmail.com"},
    {"neet","neetcode@gmail.com"}};
    auto res = accountsMerge(in);

    for(vector<string> a : res){
        for(auto b : a){
            cout << b << " ";
        }
        cout <<endl;
    }

    return 0;
}