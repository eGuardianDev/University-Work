


#include <climits>
#include <iostream>
#include <vector>

bool Veccontains(std::vector<int>& contains, int a){
    for(int i =0;i<contains.size();++i){
        if(contains[i] == a){
            return true;
        }
    }
    return false;
}


int minDistance(int dist[], bool visited[],int size){
    int index = -1, min = INT_MAX;

    for(int i =0; i<size;++i){
        if(visited[i] == false && dist[i] < min ){
            min = dist[i];
            index = i;
        }
        
    }

    return index;
}

void dijkstra( std::vector<std::vector<int>>& adjList, int start){

    std::vector<int> contain;

    for(int i =0;i<adjList.size();++i){
       if(!Veccontains(contain, adjList[i][0])){
        contain.push_back(adjList[i][0]);
       }
       if(!Veccontains(contain, adjList[i][1])){
        contain.push_back(adjList[i][1]);
       }
    }

    bool visited[contain.size()];
    int dist[contain.size()];

    for(int i =0; i<contain.size();++i){
        visited[i] = 0;
        dist[i] = INT_MAX;
    }

    dist[start] = 0;

    for(int i =0; i<contain.size();++i){
        int st = minDistance(dist,visited,contain.size());

        visited[st] = true;
        // std::cout << st << "\n";
        for(int j =0;j<adjList.size();++j){
            int from =adjList[j][0];
            int to =adjList[j][1];
            int w =adjList[j][2];
            if(from == st 
                && !visited[to]
                && dist[st] != INT_MAX
                && dist[to] > dist[st] + w){
                dist[to] = dist[st] + w;
            }
        }
    }
    
    for(int i =0;i<contain.size();++i){
        std::cout << dist[i] << " ";
    }
    std::cout << std::endl;


}

void add(std::vector<std::vector<int>>& adjList, int u, int v, int w){
    adjList.push_back({u,v,w});
    adjList.push_back({v,u,w});
}

int main(){
    std::vector<std::vector<int>> adjList;
    add(adjList, 0,1,1);
    add(adjList, 0,3,2);
    add(adjList, 1,3,1);
    add(adjList, 1,2,3);
    add(adjList, 2,3,-5);

    dijkstra(adjList,0);
    return 0;
}