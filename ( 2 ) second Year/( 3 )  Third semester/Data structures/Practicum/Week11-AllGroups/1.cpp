#include <iostream>
#include <vector>

using namespace std;

class Graph{
    
private:    
    int vertices;
    std::vector<std::vector<int>> adjecencyList;

    void DFS(int currentNode, std::vector<bool>& visited){
        visited[currentNode] = true;
        for(const int neighbor : this->adjecencyList[currentNode]){
            if(visited[neighbor] == false){
                DFS(neighbor, visited);
            }
        }
    }

public:
    Graph(int ver):vertices(ver){
        this->adjecencyList.resize(ver);
    }
    void addEdge(int u, int v){
        this->adjecencyList[u].push_back(v);
        this->adjecencyList[v].push_back(u);
    }

    Graph(const std::vector<std::vector<int>> input) : adjecencyList(input),vertices(input.size()){
    }

    int getNumberOfConnectedComponents(){
        std::vector<bool> visited(this->vertices, false);
        int counter = 0;

        for(int i =0; i < this->vertices;++i){
            if(visited[i] == false){
                this->DFS(i,visited);
                ++counter;
            }
        }

        return counter;
    }
};


int findCircleNum(vector<vector<int>>& isConnected) {
    
}

int main(){
    vector<vector<int>> isConnected
    {{1,1,0},
     {1,1,0},
     {0,0,1}};
    std::cout << findCircleNum(isConnected);
    return 0;
}