#ifndef ALGO
#define ALGO


#include "helper.hpp"

bool in_bound(int index, int size){
    if(index <0 || index >= size ) return false;
    return true; 
}


bool move(vector<int> &list, int index){

    int size = list.size();
    if(in_bound(index, size) == false) return false;

    if(list[index] == 1){
        if(in_bound(index+1,size)){
            if(list[index+1] == 0){
                swap(list[index], list[index+1]);
                return true;
            }
        }
        if(in_bound(index+2,size)){
            if(list[index+2] == 0){
                swap(list[index], list[index+2]);
                return true;
            }
        }
        return false;
    }
    else if(list[index] == 2){
        if(in_bound(index-1,size)){
            if(list[index-1] == 0){
                swap(list[index], list[index-1]);
                return true;
            }
        }
        if(in_bound(index-2,size)){
            if(list[index-2] == 0){
                swap(list[index], list[index-2]);
                return true;
            }
        }
        return false;
    }
    return false;
}


bool dfs(vector<int> list){

    if(is_list_solved(list)){
        return true;
    }
    for(int i =0; i<list.size();++i){
        vector<int> n_list = list;
        if(move(n_list,i)){
            if(dfs(n_list)){
                print(n_list);
                return true;
            }
        }
    }

    return false;
}

void start_dfs(vector<int> list){
    if(dfs(list)){
        print(list);
    }
}

#endif // ALGO