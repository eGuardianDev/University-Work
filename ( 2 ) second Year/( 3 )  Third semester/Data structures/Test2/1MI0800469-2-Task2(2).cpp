#include <climits>
#include <iostream>

#include <fstream>
#include <vector>

class Graph{

int edges = 0;

typedef std::vector<std::vector<int>> adjList;


adjList data;


    void update(int dist[], int prev[]){
        for(int i =0;i<data.size();++i){
            int from = data[i][0];
            int to = data[i][1];
            int weight = data[i][2];

            if(dist[from] != INT_MAX/2 && dist[to] > dist[from] + weight ){
                dist[to] = dist[from] + weight;
                prev[to] = from;
            }
        }
    }

    public:
    void readFile(const char * path){

    // adjList graph;
    std::fstream file(path);


    if(!file.is_open()){
        throw std::invalid_argument("File not found");
    }

    file >> edges;

    int connections;
    file >> connections ;
    int from;
    int to;
    int weight; 
    while(connections){
        file >> from;
        file >> to;
        file >> weight;

        connections--;
        data.push_back({from,to,weight});
    }
    file.close();
    }

    void printData(){
        for(auto a: data){
            std::cout << a[0] << ", "<< a[1] << ", " << a[2] << std::endl;
        }
    }





    void BellmanFord(int start, int maxLength){
        if(data.size() == 0){
            throw std::logic_error("empty graph");
        }

        int dist[edges];
        int prev[edges];

        for(int i=0;i<edges;++i){
            dist[i] = INT_MAX / 2;
            prev[i] = -1;
        }

        dist[start] = 0;


        for(int i =0;i<edges;++i){
            update(dist, prev);
        }

        for(int i =0;i<edges;++i){
            if(dist[i] <= maxLength){
                std::cout << "Node "<< i << " reachable with length "<<dist[i] << std::endl;
            }
        }

    }

};

int main(){

    Graph a;
    
    std::cout << "Enter file name: ";
    char * path = new char[255];
    std::cin >> path;
    a.readFile(path);

    std::cout << "Enter start node number: ";
    int start =0;
    std::cin >> start;
    std::cout << "Enter max range for roads: ";
    int maxRange =0;
    std::cin >> maxRange;
    a.BellmanFord(start,maxRange);
    return 0;
}