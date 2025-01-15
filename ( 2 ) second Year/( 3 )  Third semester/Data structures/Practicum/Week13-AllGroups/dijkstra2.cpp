#include <climits>
#include <iostream>
#include <vector>


int minDistance(int dist[], bool visited[], int size){
    int min = INT_MAX, index = -1;
    for(int i =0 ;i<size;++i){
        if(dist[i] <= min && visited[i] == false){
            min = dist[i]; index = i;
        }
    }
    return index;
}

void dijkstra(std::vector<std::vector<int>>& adjlist, int start){
    int size = adjlist.size();
    bool visited[size];
    int distance[size];
    int prev[size];

    for(int i =0; i<size; ++i){
        visited[i] = false;
        distance[i] = INT_MAX;
        prev[i] = -1;
    }
    distance[start] = 0;

    for(int i =0; i<adjlist.size();++i){
        int st = minDistance(distance, visited,size);

        visited[st] = true;

        for(int i =0; i<size;++i){       
            if( adjlist[st][i] >0
                && visited[i] == false
                && distance[st] != INT_MAX
                && adjlist[st][i] + distance[st] < distance[i]){
            
                distance[i] = adjlist[st][i] + distance[st];
                prev[i] = st;   
            }
        }
    }

    for(int i =0 ;i< size;++i){
        std::cout << prev[i] << " ";
    }std::cout << std::endl;
    return;
}


int main(){
    std::vector<std::vector<int>> adjList=
    {   {0,1,0,2},
        {1,0,3,1},
        {0,3,0,5},
        {2,1,5,0}};

    dijkstra(adjList, 0);
    return 0;
}