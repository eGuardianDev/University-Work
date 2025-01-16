


#include <climits>
#include <iostream>
#include <vector>
typedef std::vector<std::vector<int>> list;


void add (list& list, int u, int v, int w){
    list.push_back({u,v,w});
    list.push_back({v,u,w});
} 

void print(list& list){
    for(int i =0;i<list.size();++i){
        int from = list[i][0];
        int to = list[i][1];
        int weight = list[i][2];
        std::cout << from << " " << to << " - " << weight << "\n"; 
    }
}

int min(list& list, std::vector<int>& queue, int& next ,bool visited[],int size){
    int min = INT_MAX, index = -1;


    int curr = queue[next];
    while(visited[curr]){
        curr = queue[++next];
    }

    for(int i =0 ;i<list.size();++i){

        int from = list[i][0];
        int to = list[i][1];
        int weight = list[i][2];
        if(curr == from && !visited[to] && weight <= min) {
            min = weight;
            index =to;
        }    
    }

    return index;
}
void addChildren(list& list, int start, std::vector<int> queue){
    for(int i =0;i<list.size();++i){
        int from = list[i][0];
        int to = list[i][1];
        if(start == from){
            queue.push_back(to);
        }
    }
}

void Prim(list& List, int start, int size){

    std::vector<int> queue;
    int next = 0;

    bool visited[size];
    int prev[size];

    for(int i =0;i< size;++i){
        visited[i] = false;
        prev[i] = -1;
    }

    queue.push_back(start);
    
    int last = start;
    for(int i =0;i<size-1;++i){
        int curr = min(List, queue, next,visited,size);
        std::cout << curr<< ' ';
        addChildren(List, curr, queue);
        ++next;

        visited[curr] = true;
        prev[curr] = last;
        last = curr;
    }

    std::cout << std::endl;
    for(int i =0;i<size;++i){
        std::cout << prev[i] << ' ';
    }
    std::cout << '\n';
}


int main(){
    list List;

    add(List,0, 1, 0);
    add(List,1, 2, 5);
    add(List,2, 3, 4);
    add(List,2, 0, 1);
    // add(List, 2, 3, 1);
    // add(List, 3, 0, 2);

    int size = 4;

    print(List);
    std::vector<int> queue;
    int next = 0;

    bool visited[size];
    int prev[size];

    for(int i =0;i< size;++i){
        visited[i] = false;
        prev[i] = -1;
    }
    queue.push_back(2);
    int m = min(List,queue,next,visited,size);
    std::cout<< m;
    addChildren(List,m, queue);
    next++;
    m = min(List,queue,next,visited,size);
    std::cout<< m;
    addChildren(List,m, queue);
    next++;
    m = min(List,queue,next,visited,size);
    std::cout<< m;
    // Prim(List, 0,size);
    // print(List);
    
    return 0;
}