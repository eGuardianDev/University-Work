#include <iostream>
#include <vector>
#include <climits>




std::vector<int> algorthim(const std::vector<int> &vec, int m){
    
    std::vector<int> gas_station;

    int n =vec.size();

    int last_gas = 0;
    int starting_position = 0;
    for(int i =0;i<n;++i){ // O(n)
        if(m >= vec[i] - starting_position){
            last_gas = vec[i];
        }else{
            gas_station.push_back(i);
            starting_position = last_gas;
        }
    }

    return gas_station; 
}


int main(){

    
    std::vector<int> D = {2, 5, 7, 10, 13, 16, 21};
                        //      ^       ^
    int m = 7; // max size
    int d = 25; // distance


    for(auto a : D){
        std::cout << a << " ";
    }std::cout << std::endl;

    auto stations = algorthim(D,m);

    for(auto a : stations){
        std::cout << a << " ";
    }std::cout << std::endl;


    return 0;
}