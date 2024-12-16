#include <iostream>
#include <vector>
#include <cmath>


std::vector<std::vector<int>> permutations;

void Permutations(int n, std::vector<int>& curr, std::vector<bool>& used){
    if(curr.size() == n){
        permutations.push_back(curr);
        return;
    }

    for(int i =0;i<n;++i){
        if(used[i]) continue;
        used[i] = true;
        curr.push_back(i+1);
        Permutations(n, curr,used);
        curr.pop_back();
        used[i] = false;
    }
}
void Permutations(int n){
    std::vector<int> nums;
    std::vector<bool> used;
    while(used.size() <n){
        used.push_back(false);
    }
    Permutations(n, nums, used);
}



std::vector<std::vector<int>> matrix
{ {1,2,3},
    {2,2,1},
    {7,3,4}};


int countInversions(std::vector<int>& currentPermutations){

    int count = 0;

    int size = currentPermutations.size();
    for(int i =0;i<size-1;++i){
        for(int j =i;j<size;++j){
            if(currentPermutations[i] > currentPermutations[j]){
                ++count;
            }
        }
    }


    return count;
}
int productOfA(int index){

    std::vector<int> current = permutations[index];
    int res =1;

    for(int i=0;i<current.size();++i){
        res *= matrix[i][ current[i] -1];
    }

    return res;

}

void print(){
    int k=0;
    for(auto perm : permutations){
        std::cout << k+1 << ": ";
        for(int i =0;i<perm.size();++i){
            std::cout << perm[i] << " ";
        }
        std::cout << countInversions(permutations[k]) << '\n';

        k++;    
    }
   
    
}


int determinant(std::vector<std::vector<int>>& matrix){
    Permutations(matrix.size());
    // print();
    int res = 0;
    for(int i =0 ;i <permutations.size();++i){
        res += std::pow(-1,countInversions(permutations[i])) * productOfA(i);
    }
    return res;
}



int main(){
    std::cout << "hello world\n";
    
    std::cout <<determinant(matrix) << "\n";

    
    return 0;
}