


#include <climits>
#include <iostream>
#include <vector>

#define list  std::vector<std::vector<int>> 


int minDistance(int dist[], bool visisted[], int size){
    int min = INT_MAX, min_index = -1;
    for(int i =0;i<size;++i){
        if(visisted[i] == false && dist[i] < min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(list &edges, int start ){
    int distance[edges.size()];
    bool visited[edges.size()];
    int prev[edges.size()];

    for(int i =0; i<edges.size();++i){
        distance[i] = INT_MAX;
        visited[i] = false;
        prev[i]= -1;
    }


    distance[start] = 0;
    visited[start] = false;

    
    for(int i=0;i<edges.size()-1;++i){
        
        int u = minDistance(distance,visited,edges.size());
        visited[u] = true;

        for(int k=0;k<edges.size();++k){
            if(!visited[k]
             && edges[u][k] > 0
             && distance[u] != INT_MAX
             && distance[u] + edges[u][k] < distance[k]){
                distance[k] = distance[u] + edges[u][k];
                prev[k] = u;
            }
        }

    }




    for(int i=0;i<edges.size();++i){
        std::cout << distance[i] << " ";
    }
    std::cout << "\n";

    for(int i=0;i<edges.size();++i){
        std::cout << prev[i] << " ";
    }
    std::cout << "\n";

    return;
}


int main(){
    std::vector<std::vector<int>> edges=
    {   {0,1,0,2},
        {1,0,3,1},
        {0,3,0,5},
        {2,1,5,0}};
    dijkstra(edges, 0);
    return 0;
}