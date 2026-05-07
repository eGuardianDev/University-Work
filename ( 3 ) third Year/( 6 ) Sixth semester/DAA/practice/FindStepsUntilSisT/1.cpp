#include <iostream>


int steps(int s, int t){
    int count =0;

    while(s <t){
        s = s*2;
        count++;
    }

    while(s >t){
        s = s-1;
        count++;
    }

    return count;
}

int main(){

    std::cout << steps(8,5) << std::endl;

    return 0;
}