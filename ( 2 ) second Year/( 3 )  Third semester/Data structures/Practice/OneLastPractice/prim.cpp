

#include <climits>
#include <iostream>
#include <utility>
#include <vector>


class graph{

typedef std::vector<int> row;
typedef std::vector<row> matrix;

    matrix data;
    

    int minDist(bool visited[], int distance[],int size){

        int min = INT_MAX, index = -1;
        for(int i=0;i<size; ++i){
            if(!visited[i] && distance[i] <= min){
                min = distance[i];
                index = i;
            }
        }
        return index;
    }

public:
    graph(int n){
        data = matrix(n);
        for(int i =0;i<n;++i){
            data[i] = row(n,0);
        }
    }

    void add(int from, int to, int weight){
        data[from][to] = weight;
    }

    void dijkstra(int start){

        int size = data.size();
        bool visited[size];
        int dist[size];
        int prev[size];

        for(int i=0;i<size;++i){
            dist[i] = INT_MAX/2;
            visited[i] = false;
            prev[i] = -1;
        }
        
        dist[start] = 0;

        for(int i=0;i<size-1;++i){

            int st = minDist(visited,dist, size);

            visited[st] = true;


            for(int i=0;i<data[st].size();++i){
                if(data[st][i] && !visited[i] && dist[i] > data[st][i]){
                    dist[i] = data[st][i] ;
                    prev[i] = st;
                }
            }
        } 


        for(int i =0;i<size;++i){
            std::cout<<dist[i] << " ";
        }
        std::cout <<std::endl;
        for(int i =0;i<size;++i){
            std::cout<<prev[i] << " ";
        }
        std::cout <<std::endl;

    }

};

int main(){

    graph temp(6);
    temp.add(0,1, 1);
    temp.add(0,2, 1);
    temp.add(2,3, 1);
    temp.add(2,4, 2);
    temp.add(4,5, 5);
    temp.add(3,5, 8);

    temp.dijkstra(0);
    return 0;
}
