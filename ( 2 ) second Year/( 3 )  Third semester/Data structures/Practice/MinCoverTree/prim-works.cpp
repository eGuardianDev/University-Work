#include <climits>
#include <iostream>
#include <vector>


typedef std::vector<std::vector<int>> matrix;

int minDist(bool visited[], int dist[], int size ){

    int min = INT_MAX, index = -1;
    for(int i =0; i<size;++i){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            index= i;
        }
    }
    return index;
}


void Prim(matrix& graph, int start){

    int size = graph.size();
    bool visited[size];
    int dist[size];
    int prev[size];
    for(int i=0;i<size;++i){
        visited[i] = false;
        dist[i] = INT_MAX;
        prev[i] = -1;
    }

    dist[start] = 0;

    for(int i =0;i<size-1;++i){
        int st= minDist(visited,dist,size);

        visited[st] = true;

        for(int k =0;k<size;++k){
            if(graph[st][k] && !visited[k] && dist[k] > graph[st][k] ){
                dist[k] = graph[st][k];
                prev[k] = st; 
            }
        }
    }

    for(int i =0;i<size;++i){
        // this is cost from prev[i] to i
        // if you want to the sum cost, need to backtrack until start
        // and sum while doing it
        std::cout << dist[i] << " ";
    }
        std::cout << "\n";
    for(int i =0;i<size;++i){
        std::cout << prev[i] << " ";
    }
    std::cout << "\n";


}

int main(){

    matrix graph ={
    {0,1,0,2},
    {1,0,3,1},
    {0,3,0,5},
    {2,1,5,0}};

    Prim(graph,0);

    return 0;
}