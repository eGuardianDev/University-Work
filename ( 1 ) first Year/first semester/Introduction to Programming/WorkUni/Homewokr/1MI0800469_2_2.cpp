#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
int main(){

    int n = 0;
    int sum = 0;

    std::cin >> n ;
    if(fmod(log2(n),1) !=0){ std::cout << "invalid size;"; return 1;}

    int temp = 0;
    for(int  i=0 ;i  < n; i++){
        std::cin >> temp;
        if(temp == 1){
            sum ^= i;
        }
    }
    cout << sum;
    
    return 0;
}
