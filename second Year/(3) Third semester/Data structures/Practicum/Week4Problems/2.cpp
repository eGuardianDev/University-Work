#include <iostream>
#include <stack>
#include <sys/wait.h>

template<typename T>
void reverse(std::stack<T> &input){
    std::stack<T> temp;

    while(!input.empty()){
        temp.push(input.top());
        input.pop();
    }

    input = temp;
} 

int main(){
    int n;
    std::cin >> n;
    std::stack<int> random;
    for(int i =0 ;i<n ;i++){
        int temp;
        std::cin >> temp;
        random.push(temp);
    }


    reverse(random);
    
    while(!random.empty()){
        std::cout << random.top();
        random.pop();
    }


    return 0;
}