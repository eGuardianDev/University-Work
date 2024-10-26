#include <iostream>
#include <vector>

template<class T>
void Display(std::vector<T> d){
    for(T a : d){
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

void Combinations(std::vector<int> display, std::vector<bool>used, int n, int k, int step){
    
    if(step == k){
        Display(display);
        return;
    }


    for(int i = 0; i< n;i++){
        if(used[i]){continue;}
        used[i] = true;
        display[step] = i+1;
        Combinations(display, used,  n,  k, step+1);
        used[i] = false;
    }

}
void Combinations(int n, int k){

    // for(int i =0 ;i<n;i++){
        Combinations(std::vector<int>(k), std::vector<bool>(n),n, k ,0);
    // }
    
}


int main(){
    int n,k;
    std::cin >> n >>k;
    Combinations(n,k);
    return 0;
}


