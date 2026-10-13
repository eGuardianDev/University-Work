#ifndef ALGO
#define ALGO


#include "helper.hpp"

// inline bool in_bound(int index, int size){
//     if(index <0 || index >= size ) return false;
//     return true; 
// }

inline int move(vector<short> &list, int &index, int &size){
    if(list[index] == 1){
        if(index+1 < size && list[index+1] == 0){
            swap(list[index], list[index+1]);
            return index+1;
        } else if(index+2 < size && list[index+2] == 0){
            swap(list[index], list[index+2]);
            return index+2;
        } else{
            return -1;
        }
    }
    else if(list[index] == 2){
        if(index-1 >=0 && list[index-1] == 0){
            swap(list[index], list[index-1]);
            return index-1;
        
        }else if(index-2 >=0 && list[index-2] == 0){
            swap(list[index], list[index-2]);
            return index-2;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

bool dfs(vector<short>& list){

    if(is_list_solved(list)){
        return true;
    }
    int size = list.size();
    for(int i =0; i<size;++i){
        int n_index = move(list,i,size);
        if(n_index != -1){
            if(dfs(list)){
                print(list);
                swap(list[i], list[n_index]);
                return true;
            }
            swap(list[i], list[n_index]);
        }
    }

    return false;
}

inline void start_dfs(vector<short> &list){
    if(dfs(list)){
        print(list);
    }
}

#endif // ALGO