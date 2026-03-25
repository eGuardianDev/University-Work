#include <iostream>
#include <vector>
#include <climits>


int alg(std::vector<int> &array){
    

    int maxSum = 0, currentSum = 0; // O(2)

    for(int i =0;i<array.size();++i){ // O(n)
        
        currentSum += array[i]; // O(1)
        maxSum = std::max(currentSum, maxSum); // O(1)
        if(currentSum <0) { // O(1)
            currentSum = 0; // O(1)
        }
    }
    return maxSum; // O(1)
}


int slow_alg(std::vector<int> &array){ // O(n^2)

    // O(1) + O(n * (n*1 + 1 +1 )) + O(1)
    // O(2) + O(n * n + n*2 ) = O(n^2 + 2*n + 2) = O(n^2)
    int maxSum = 0, current = 0; // O(1)
    for(int i =0;i<array.size();++i){ // O(n)
        for(int j =i;j<array.size();++j){ // O(n)
            current += array[j]; // O(1)
        }
        maxSum = std::max(maxSum, current); // O(1)
        current = 0; //O(1)
    }
 
    return maxSum; // O(1)
}

// int sliding_window(std::vector<int> &array){
//     int maxSum =0, current = 0;

//     int pointer = 0;
//     int length = 0;

//     while(pointer + length < array.size()){
        
//         current += array[pointer+length];
  
//         if(current > maxSum){
//             maxSum = current;
//             ++length;
//         }else{

//         }

//     }

//     return maxSum;

// }


int smallest_prefix(std::vector<int> & array){

    int prefix = 0;
    int minPrefix = 0;
    int maxSum = INT_MIN;

    for(auto a : array){
        prefix+=a;
        maxSum = std::max(maxSum, prefix-minPrefix);
        minPrefix = std::min(minPrefix, prefix);
    }

    return maxSum;

}


//  |
// -2,7,-3,4
//  ^





int main(){


    std::vector<int> array = {-2,7,-3,4};
    
    for(auto num : array){
        std::cout << num << " ";
    } std::cout << std::endl;

    std::cout << "Max sum is " << smallest_prefix(array) << std::endl;
    
    // O( 2+ n*(1+1+1+1) + 1 ) = O(3 +4n ) = O(n)

    return 0;
}