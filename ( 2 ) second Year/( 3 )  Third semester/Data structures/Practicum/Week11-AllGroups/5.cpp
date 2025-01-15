

#include <iostream>
#include <queue>
#include <vector>




std::vector<int> loudAndRich(std::vector<std::vector<int>>& richer, std::vector<int>& quiet) {
     std::vector<std::vector<int>> list(quiet.size());
    std::vector<int> res(quiet.size()), 
    indegree(quiet.size(),0), 
    ans(quiet.size());
    
    for(int i =0;i<quiet.size();++i){
        ans[i] = i;
    }

    for(int i =0;i<richer.size();++i){
        list[richer[i][0]].push_back(richer[i][1]);
        ++indegree[richer[i][1]];
    }

    
    std::queue<int> que;
    for(int i =0;i<indegree.size();++i){
        if(indegree[i] ==0){
            que.push(i);
        }
    }


    while(!que.empty())
    {
        int node = que.front();
        que.pop();

        for(auto i : list[node]){
            if(quiet[ans[node]] < quiet[ans[i]]){
                ans[i] = ans[node];
            }
            if(--indegree[i] == 0){
                que.push(i);
            }
        }
    }

    return ans;
}

int main(){
    std::vector<std::vector<int>> richer=
    {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};

    std::vector<int> quiet ={3,2,5,4,6,1,7,0};

    //    std::vector<std::vector<int>> list(quiet.size());

    // for(int i =0;i<richer.size();++i){
    //     list[richer[i][1]].push_back(richer[i][0]);
    // }
    
    std::vector<int> res = loudAndRich(richer,quiet);
    // for(int i =0;i<list.size();++i){
    //     std::cout << i << "->" ;
    //     for(auto b: list[i]){
    //         std::cout << b << " ";
    //     }
    //     std::cout << '\n';
    // }

    for(auto a :res){
        std::cout << a << " ";
    }
    std::cout << '\n';
    


    return 0;
}