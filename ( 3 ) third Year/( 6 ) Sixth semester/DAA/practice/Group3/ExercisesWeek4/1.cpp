#include <iostream>
#include <vector>
#include <climits>




int algorthim(const std::vector<int> &vec){

    if(vec.size() == 0) return 0;

    int maxProfit = 0;

    int lowestPrice = vec[0];
    int currentProfit = 0;


    for(int i =1;i<vec.size();++i){
        currentProfit = vec[i] - lowestPrice;
        maxProfit = std::max(currentProfit, maxProfit);
        lowestPrice = std::min(lowestPrice, vec[i]);
    }

    return maxProfit;
}


int main(){

    // std::vector<int> vec = {7,1,5,3,6,4}; 
    std::vector<int> vec = {7,6,4,1}; 

    for(auto a : vec){
        std::cout << a << " ";
    }std::cout << std::endl;

    std::cout << "max profit: " << algorthim(vec) << std::endl;


    return 0;
}