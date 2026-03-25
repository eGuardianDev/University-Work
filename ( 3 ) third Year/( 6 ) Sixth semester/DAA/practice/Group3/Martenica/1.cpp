
#include <iostream>
#include <vector>



void martenica(std::vector<int> &A){

    for(int k =0; k< A.size()-1; ++k){ // O(n)
        
        if((k+1) % 2 != 0){
            //odd
            if(A[k] <= A[k+1]){
                // good
            }else{ // A[k] > A[k+1]
                std::swap(A[k], A[k+1]);
            }
        }else{
            //even
            if(A[k] >= A[k+1]){
                // good
            }else{ // A[k] < A[k+1]
                std::swap(A[k], A[k+1]);
            }
        }
    }
}


int main(){

    // 1, 0, 1
    // 6, 1, 4
    // std::vector<int> list = {6, 1, 4, 2, 8, 7, 3, 5};
    std::vector<int> list = {1,2,3,4,5,6,7,8};


    for(auto element : list){
        std::cout << element << " ";
    }   std::cout << std::endl;

    martenica(list);


    for(auto element : list){
        std::cout << element << " ";
    }   std::cout << std::endl;


    return 0;
}