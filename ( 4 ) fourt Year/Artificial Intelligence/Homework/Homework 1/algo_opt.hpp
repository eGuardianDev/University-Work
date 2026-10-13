#ifndef ALGO
#define ALGO


#include "helper.hpp"


bool dfs(vector<short> &list, int &index, int &size){
    if(is_list_solved(list)){
        return true;
    }

    // print(list);
    
    for(int i =1;i<=2;++i){
        int frog_right = index + i;
        if(frog_right < size && list[frog_right] == 2) {
            swap(list[frog_right], list[index]);
            if(dfs(list,frog_right,size)){
                print(list);
                swap(list[frog_right], list[index]);
                return true;
            }
            swap(list[frog_right], list[index]);
        }
    }

    for(int i =1;i<=2;++i){
        int frog_left = index - i;
        if(frog_left >= 0 && list[frog_left] == 1) {
            swap(list[frog_left], list[index]);
            if(dfs(list,frog_left,size)){
                print(list);
                swap(list[frog_left], list[index]);
                return true;
            }
            swap(list[frog_left], list[index]);
        }
    }


    return false;
}

inline void start_dfs(vector<short> &list){
    int size = list.size();
    int middle = size/2;
    if(dfs(list, middle, size)){
        print(list);
    }else{
        std::cout << "Solution not found" << std::endl;
    }
}

#endif // ALGO