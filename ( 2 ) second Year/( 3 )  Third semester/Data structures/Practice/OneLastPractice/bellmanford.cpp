

#include <climits>
#include <iostream>
#include <utility>
#include <vector>


class graph{

typedef std::vector<int> row;
typedef std::vector<row> matrix;

    matrix data;
    
    void update(int dist[], int size){
        for(int i =0;i<size;++i){
            int from = i;
            for(int j =0;j<size;++j){
                int to =j;
                int weight = data[from][to];
                if(data[from][to] && dist[to] > dist[from] + weight)
                {
                    dist[to] = dist[from] + weight;
                }
            }
        }

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

    void bellmanFord(int start){

        int size = data.size();
        int dist[size];
        for(int i =0;i<size;++i){
            dist[i] = INT_MAX/2;
        }

        dist[start] = 0;

        for(int i =0;i<size-1;++i){
            update(dist, size);
        }
        
        for(int i =0;i<size;++i){
            std::cout << dist[i]<< " ";
        }
        std::cout << std::endl;


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

    temp.bellmanFord(0);
    return 0;
}
