#include <climits>
#include <iostream>
#include <vector>

void update(std::vector<std::vector<std::pair<int,int>>>& adjList, int dest[], int prev[], int size){
    for(int i =0;i<adjList.size();++i){
        int from = i;
        bool flag = false;
        for(int j =0; j< adjList[i].size();++j){
            int to = adjList[i][j].first;
            int w = adjList[i][j].second;

            if(dest[to] > dest[from] + w){
                dest[to] = dest[from] + w;
                prev[to] = from;
                // flag = true;
            }
        }
        // if(flag) return;
    }
}
void bellmanFord(std::vector<std::vector<std::pair<int,int>>>& adjList, int start){

    int size =adjList.size();
    int dest[size];
    int prev[size];

    for(int i =0;i<size;++i){
        dest[i] = INT_MAX/2;
        prev[i] = -1;
    }

    dest[start] = 0;

    for(int i =0; i<size-1;++i){
        update(adjList,dest,prev,size);
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

    int n = 6;
    // int n = 4;
    // int n = 3;
    std::vector<std::vector<std::pair<int,int>>> adjlist(n);

    adjlist[0].push_back({1,10});
    adjlist[0].push_back({5,8});
    adjlist[1].push_back({3,2});
    adjlist[2].push_back({1,1});
    adjlist[3].push_back({2,-2});
    adjlist[4].push_back({3,-1});
    adjlist[4].push_back({1,-4});
    adjlist[5].push_back({4,1});

    // adjlist[1].push_back({0,4});
    // adjlist[1].push_back({2,-6});
    // adjlist[2].push_back({3,5});
    // adjlist[3].push_back({1,-2});

    // adjlist[0].push_back({2,4});
    // adjlist[0].push_back({1,3});
    // adjlist[2].push_back({1,-2});

    bellmanFord(adjlist, 0);

    return 0;
}