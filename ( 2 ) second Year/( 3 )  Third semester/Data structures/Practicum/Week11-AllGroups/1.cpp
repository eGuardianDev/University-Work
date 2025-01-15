#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& connect, std::vector<bool>& visited, std::vector<int>& list, int start =0){
    visited[start] = true;
    list.push_back(start);
    int n =connect.size();
    for(int i =0;i<n;++i){
        if(connect[start][i]==1 && visited[i] == false){
            bfs(connect, visited, list, i);
        }
    }
}
int hasTrue(std::vector<bool>& list){
    for(int i=0;i<list.size();++i){
        if(list[i]) return i;
    }
    return -1;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    std::vector<bool> visited(isConnected.size(),false);
    std::vector<int> list;
    std::vector<bool> toVisit(isConnected.size(), true);
    int provinces =0;
    int a;
    while((a = hasTrue(toVisit)) != -1){
        bfs(isConnected, visited,list, a);
        for(auto a : list){
            toVisit[a] = false;
        }
        provinces++;
    }
    return provinces;
}

int main(){
    vector<vector<int>> isConnected=
    {{1,1,0},
     {1,1,0},
     {0,0,1}};

    
    return 0;
}