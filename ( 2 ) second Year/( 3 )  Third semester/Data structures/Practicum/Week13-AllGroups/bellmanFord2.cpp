#include <climits>
#include <iostream>
#include <vector>

void update(std::vector<std::vector<int>>& graph, int dest[], int prev[], int size){

    for(int i =0;i<size;++i){
        for(int j=0;j<size;++j){
            if(graph[i][j]!=0 && dest[j]> dest[i] + graph[i][j] ){
                dest[j] = dest[i] + graph[i][j];
                prev[j] = i;
            }
        }

    }

}

void bellmandFord(std::vector<std::vector<int>>& graph, int start){

    int size = graph.size();
    int dest[size];
    int prev[size];

    for(int i =0;i<size;++i){
        dest[i] = INT_MAX/2;
        prev[i] = -1;
    }
    dest[start] = 0;

    for(int i =0;i<size-1;++i){
        update(graph, dest, prev, size);
    }

    for(int i =0;i<size;++i){
        for(int j =0;j<size;++j){
            if(graph[i][j] != 0 && dest[j] > dest[i] + graph[i][j]){
                std::cout << "Graph contains negative loop";
                return;
            }
        }
    }

    for(int i =0;i<size;++i){
        std::cout << dest[i] << ' ';
    }
    std::cout << "\n";
    for(int i =0;i<size;++i){
        std::cout << prev[i] << ' ';
    }
    std::cout << "\n";
}

int main(){

    std::vector<std::vector<int>> graph =
    {
        {0,10,0,0,0,8},
        {0,0,0,2,0,0},
        {0,1,0,0,0,0},
        {0,0,-2,0,0,0},
        {0,-4,0,-1,0,0},
        {0,0,0,0,1,0}
    };
    bellmandFord(graph, 0);

    return 0;
}