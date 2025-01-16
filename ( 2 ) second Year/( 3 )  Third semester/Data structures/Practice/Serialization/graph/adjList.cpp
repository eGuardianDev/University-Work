
#include <iostream>
#include <vector>
#include <fstream>

typedef std::vector<std::vector<std::pair<int, int>>> graph;

void deserializeAdjGraph(graph& adjlist){

    std::fstream f("adjData.txt");

    int from;
    int to;
    int weight;
        
    while(f >> from>> to>> weight){
        while(adjlist.size() < from+1){
            adjlist.push_back(std::vector<std::pair<int, int>>(0));
            
        }
        adjlist[from].push_back({to, weight});
    }
    f.close();

}


int main(){
    graph adjlist(0);
    deserializeAdjGraph(adjlist);

    for(int i =0;i<adjlist.size();++i){
        std::cout << i << " -> ";
        for(int j=0;j<adjlist[i].size();++j){
            std::cout << " { "<< adjlist[i][j].first << " " << adjlist[i][j].second << " } ";
        }
        std::cout <<'\n';
    }

    return 0;
}