
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

string foreignDictionary(vector<string>& words) {
    unordered_map<char,set<char>> graph;
    vector<char> order; // insertion order

    for(auto a : words){
        for(int i = 0; i< a.size();++i){

            if (graph.find(a[i]) == graph.end()) {
                graph[a[i]] = {};
                order.push_back(a[i]);  // record first seen
            }
            for(int j =i+1;j < a.size();++j){
                if(a[j] == a[i]) continue;
    
                graph[a[j]].insert(a[i]);
    
            }
        }
    }


    for(auto& [a,b]:graph){
        cout << "key " << a <<endl;
        for(auto el : b){
            cout << " " << el;
        }cout << endl;
    }

    string res = "";
    while(graph.size()){
        int min_val = INT_MAX;
        char min_elem = '1';
        for (const char key : order) {
            if (graph.find(key) == graph.end()) continue;  // already erased
            if(min_val > graph[key].size()){
                min_val = graph[key].size();
                min_elem = key;
            }
        }

        res += min_elem;

        
        graph.erase(min_elem);
        
        for(auto& [a,b]:graph){
            b.erase(min_elem);
        }

    
    }
    return res;
}


int main(){

    vector<string> words = {"hrn","hrf","er","enn","rfnn"};
    // vector<string> words = {"z","o"};

    cout << foreignDictionary(words) << endl;
    return 0;
}