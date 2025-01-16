

#include <iostream>
#include <vector>

typedef std::vector<std::pair<int,int>> list;
typedef std::vector<list> adjList; 

void add(adjList& graph, int u, int v,int w){
    while(graph.size() < std::max(u,v)+1){
        graph.push_back(list(0));
    }

    graph[u].push_back(std::pair<int,int>(v,w));
    graph[v].push_back(std::pair<int,int>(u,w));

}
void print(adjList graph){
    for(int i =0;i<graph.size();++i){
        std::cout << i << " ->";
        for(int j=0;j<graph[i].size();++j){
            std::pair vals = graph[i][j];
            std::cout << " { " << vals.first << ", " << vals.second << " } ";
        }
        std::cout << '\n';
    }
}

void minNext (){

}

void Prim(adjList& graph, int start){



}

int main(){
    adjList graph;

    add(graph, 0,1,2);
    add(graph, 2,3,2);
    print(graph);
    return 0;
}