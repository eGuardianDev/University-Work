#include <cassert>
#include <iostream>
#include <queue>
#include <vector>


class queue{
    struct Node{
        
        int val = 0;
        Node* next = nullptr;
        
        void Destruct(){
            if(next) next->Destruct();
            delete next;
        }
    } *root = nullptr, *tail= nullptr;

    public:
    ~queue(){if(root){root->Destruct(); tail = nullptr; root =nullptr;}}

    void push(int val){
        if(root == nullptr){
            root = new Node{val, nullptr};
            tail = root;
        }else{
            tail->next = new Node{val,nullptr};   
            tail = tail->next;
        }
    }
    int& front(){
        assert(root);
        return root->val;
    }
    bool empty(){
        return root == nullptr;
    }
    void pop(){
        assert(root);
        if(root->next){
            Node *temp = root;
            root = root->next;
            delete temp;
        }else{
            tail =nullptr;
            root = nullptr;
            delete root;
        }
    }


};


bool isBipartite(std::vector<std::vector<int>>& adjList, int size){

    std::vector<int> color(size, -1);
    
    std::queue<int> q;

    for(int i =0;i<size;++i){

        if(color[i] == -1){
            color[i] = 0;
            q.push(i);

            while(!q.empty()){
                int u = q.front(); q.pop();

                for(int j =0; j < adjList[u].size(); ++j){

                    if(color[adjList[u][j]] == -1){
                        color[adjList[u][j]] = 1 - color[u];
                        q.push(adjList[u][j]);
                    }
                    else if(color[u] == color[adjList[u][j]]){
                        return false;
                    }

                }

            }

        }

    }


    return true;
}

int main(){
   int V = 4;
    std::vector<std::vector<int>> adj(V);
    
    // Adding edges (undirected)
    // adj[0].push_back(2);adj[2].push_back(0);
    // adj[0].push_back(3);adj[3].push_back(0);
    // adj[0].push_back(1);adj[1].push_back(0);
    
    // adj[2].push_back(1);adj[1].push_back(2);

    // adj[3].push_back(2);adj[2].push_back(3);

    
    
    adj[0].push_back(1); adj[1].push_back(0); 
    adj[1].push_back(2); adj[2].push_back(1);  
    adj[2].push_back(3); adj[3].push_back(2);  
    adj[3].push_back(0); adj[0].push_back(3);
    
    std::cout << isBipartite(adj, V);

    return 0;
}