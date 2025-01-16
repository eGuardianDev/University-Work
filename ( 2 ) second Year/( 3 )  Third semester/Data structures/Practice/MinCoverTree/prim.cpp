


#include <climits>
#include <iostream>
#include <queue>
#include <random>
#include <stdexcept>
#include <vector>

class priorityQueue{
    struct Node{
        int val = 0;
        int weight = 0;
        Node *next = nullptr;
        void destruct(){
            if(next) next->destruct();
            delete this;
        }
    };

    Node* root = nullptr;

    public:
    priorityQueue(){}
    ~priorityQueue(){if(root)root->destruct();}
    void add(int v, int w){
        if(!root){
            root = new Node{v,w};
        }else{
            Node* temp = root;
            Node* prev = nullptr;
            while(temp && temp->weight < w){
                prev = temp;
                temp = temp->next;
            }
            if(!prev){
                root = new Node{v,w,root};
            }else{
                prev->next = new Node{v,w,temp};
            }

        }
    }
    bool empty(){
        return root == nullptr;
    }
    void pop(){
        if(root){
            Node* del = root;
            root = root->next;
            delete root;
        }
    }
    int val(){
        if(root){
            return root->val;
        }else{
            throw std::underflow_error("underflow");
        }
    }
    int weight(){
        if(root){
            return root->weight;
        }else{
            throw std::underflow_error("underflow");
        }
    }


};

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


void Prim(list& List, int start, int size){


    bool visited[size];
    int cost[size];
    int prev[size];

    for(int i =0;i< size;++i){
        visited[i] = false;
        cost[i] = INT_MAX;
        prev[i] = -1;
    }
    

    priorityQueue queue;
  
    for(int i =0;i<List.size();++i){
        int from = List[i][0];
        int to = List[i][1];
        int weight = List[i][2];
        queue.add(to, weight);
        to = queue.val();
        weight = queue.weight();
        // queue.pop();
        std::cout << to << " " << weight << '\n';
    }
    int to = queue.val();
    int weight = queue.weight();
    // for(int i =0;i<List.size();++i){
    //     queue.pop();
    // }
    
    
    while(!queue.empty())
    {
        // int v = queue.weight();
        // std::cout << v <<'\n';
        // queue.pop();
        // for(int i=0;i<List.size();++i){
        //     int from = List[i][0];
        //     int to = List[i][1];
        //     int weight = List[i][2];
        //     if(from == v){
        //         if(cost[to] > weight){
        //             cost[to] = weight;
        //             prev[to] = from;
        //         }
        //     }
        // }   
    }

    // for(int i =0;i<size;++i){
    //     std::cout << cost[i] << ' ';
    // }
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
    Prim(List, 0,size);
    
    return 0;
}