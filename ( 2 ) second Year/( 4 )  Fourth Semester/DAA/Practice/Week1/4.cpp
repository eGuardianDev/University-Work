#include <bits/stdc++.h>
#include <cmath>


std::stack<long long> data;

int main(){

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin.tie(NULL);


    long long input = 0;
    
    while(std::cin >> input){
        data.push(input);
    } 

    while(!data.empty()){
        double ans = std::sqrt(data.top());
        std::cout << std::fixed << std::setprecision(6) << ans << std::endl;
        data.pop();
    }

    return 0;
}