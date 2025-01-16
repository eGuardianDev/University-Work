#include <climits>
#include <iostream>
#include <vector>


int minDest(int dest[], bool visited[], int size ){

    int minVal = INT_MAX, index = -1;
    for(int i =0;i<size;++i){
        if(!visited[i] && dest[i] <= minVal){
            minVal = dest[i];
            index = i;
        }
    }
    return index;
}

bool contains(std::vector<int> vect, int val){
    for(int i =0;i<vect.size();++i){
        if(val == vect[i]) return true;
    }

    return false;
}
void dijstra(std::vector<std::vector<int>>& list, int start){

    std::vector<int> elems;
    for(int i =0; i<list.size();++i){
        if(!contains(elems, list[i][0])){
            elems.push_back(list[i][0]);
        }
        if(!contains(elems, list[i][1])){
            elems.push_back(list[i][1]);
        }
    }

    // std::cout << list.size();
    // std::cout <<elems.size();

    int size = elems.size();
    int dest[size];
    bool visited[size];
    int prev[size];

    for(int i =0;i<size;++i){
        dest[i] = INT_MAX;
        prev[i] = -1;
    }

    dest[start] = 0;


    for(int i =0;i<size-1;++i){
        int st = minDest(dest, visited, size);
        visited[st] = true;

        for(int j =0;j<list.size();++j){
            int from = list[j][0];
            int to = list[j][1];
            int w = list[j][2];

            if(from == st &&
                dest[from] != INT_MAX &&
                !visited[to]&&
                dest[to] > dest[from] + w){
                    dest[to] = dest[from] +w;
                    prev[to] = from;
            }
        }

    }
    std::cout << '\n';

    // for(int i =0;i<size;++i){
    //     std::cout << dest[i] << ' ';
    // }
    // std::cout << std::endl;
    // for(int i =0;i<size;++i){
    //     std::cout << prev[i] << ' ';
    // }
    std::cout << std::endl;

    std::vector<std::pair<int,int>> graph;
    for(int i =0;i<size;++i){
        graph.push_back({i,prev[i]});
    }

    for(int i =0;i<size;++i){
        std::cout << i << " " << graph[i].second << "\n";
    }

}


void add(std::vector<std::vector<int>>& adjList, int u, int v, int w){
    adjList.push_back({u,v,w});
    adjList.push_back({v,u,w});
}
int main(){
 std::vector<std::vector<int>> adjList;
    add(adjList, 0,1,1);
    add(adjList, 1,2,5);
    add(adjList, 2,3,1);
    add(adjList, 1,3,1);
    add(adjList, 2,4,5 );
    add(adjList, 3,4,2);
    add(adjList, 4,1,3);

    dijstra(adjList,0);
    return 0;
}