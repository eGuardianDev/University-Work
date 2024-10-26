#include <iostream>
#include <vector>

template<class T>
void display(std::vector<T> disp){
    for(auto a : disp) std::cout << a << " ";
    std::cout << std::endl;
}

int Permutations(std::vector<int> toDisplay, std::vector<bool> used,int n, int index, int count ){

    if(count == n){
        display(toDisplay);
        return 0;
    }
    
    for(int i =0 ;i< n; i++){

        if(used[i] == true){
            continue;
        }
        used[i] = true;
        toDisplay[index] = i+1;
        Permutations(toDisplay,  used,  n,  (index+1),  (count+1) );
        used[i] = false;
        toDisplay[index] = 0; // not needed
    }


    return 0;
}

int Permutations(int n){
    Permutations(std::vector<int>(n),std::vector<bool>(n), n, 0,0);
    return 0;
}

int main(){
    int n;
    std::cin >> n;
    Permutations(n);
    return 0;
}