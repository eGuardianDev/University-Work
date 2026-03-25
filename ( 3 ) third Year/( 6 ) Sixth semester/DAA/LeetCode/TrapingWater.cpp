
#include <iostream>
#include <vector>



int alg( std::vector<int>& list){

    if(list.size() ==0){
        return 0;
    }

    int l =0;
    int height = list[0];

    std::vector<int> waterL(list.size());
    std::vector<int> waterR(list.size());

    int max =list[0];
    waterL[0] =max;
    for(int i =1;i <list.size();++i){
        max = std::max(max,list[i]);
        waterL[i] = max;
    }
    
    max =list[list.size()-1];
    waterL[list.size()-1] =max;
    
    for(int i =list.size()-1; i>=0;--i){
        max = std::max(max,list[i]);
        waterR[i] = max;
    }


    // for(auto a : waterL){
    //     std::cout << a <<" ";
    // } std::cout << std::endl;
    // for(auto a : waterR){
    //     std::cout << a <<" ";
    // } std::cout << std::endl;


    for(int i =1;i <list.size();++i){
        max = std::min(waterL[i],waterR[i]);
        waterL[i] = max;
    }

    // for(auto a : waterL){
    //     std::cout << a <<" ";
    // } std::cout << std::endl;
    
    int water =0;
    for(int i =0;i<list.size();++i){
        water += waterL[i] -list[i];
    }

    return water;
}


int main(){
    
    std::vector<int> vector = {0,1,0,2,1,0,1,3,2,1,2,1};

    std::cout << alg(vector) << std::endl;

    return 0;
}