#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

int diff(string w1, string w2){
    int count =0;
    for(int i =0;i<w1.size();++i)
    {
        if(w1[i] != w2[i]) ++count;
    }
    return count;
}

int bfs(string start, string end, unordered_map<string, vector<string>> &graph, set<string> &visited){

    queue<string> list;
    list.push(start);
    visited.insert(start);

    int count = list.size();
    int res = 0;
    while(!list.empty()){
        count--;
        if(count == 0){
            res++;
            count = list.size();
        }
        string u = list.front(); list.pop();

        if(u == end) return res;

        for(auto v : graph[u]){
            
            if(visited.count(v)) continue;
            visited.insert(v);
            list.push(v);
        }
    }

    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    unordered_map<string, vector<string>> graph;

    queue<string> next;

    next.push(beginWord);
    
    set<string> visited;

    while(!next.empty()){
        string u = next.front(); next.pop();
        visited.insert(u);
        for(auto other : wordList){
            if(diff(u,other) == 1){
                graph[u].push_back(other);
                if(visited.count(other)) continue;
                visited.insert(other);
                next.push(other);
            }
        }
    }
    
    // for(auto &[u,adj]:graph){
    //     cout << u << " : ";
    //     for(auto v :adj){
    //         cout << v <<" ";
    //     } cout <<endl;
    // }

    set<string> visited1;

    return bfs(beginWord,endWord,graph,visited1);
}

int main(){
    
    string beginWord = "cat";
    string endWord = "sag";

    vector<string> words = {"bat","bag","sag","dag","dot"};


    cout << ladderLength(beginWord, endWord, words) << endl;

    return 0;
}