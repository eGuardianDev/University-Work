#include <climits>
#include <iostream>
#include <vector>


struct Edge{
    int to;
    int weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

class Graph{

private:
    int verticies;
    std::vector<std::vector<Edge>> adjencyList;

public:
    Graph(int verticies): verticies(verticies){
        this->adjencyList.reserve(this->verticies);
    }

    void addEdge(int u, int v, int weight){
        this->adjencyList[u].push_back(Edge(v,weight));
        this->adjencyList[v].push_back(Edge(u, weight));
    }

    void dijkstra(int src){
        std::vector<bool> used(verticies, false);
        std::vector<int> dist(verticies, INT_MAX);
    }


};


int main(){
    std::cout << INT_MAX << std::endl;
    return 0;
}