#include <iostream>
#include <queue>
#include <stack>

int is_it_storable(std::queue<int> &queue){

    int size = queue.size();
    if(size == 0){
        return -1;
    }

    std::stack<int> stack;
    stack.push(queue.front());
    queue.pop();

    for(int i =1 ;i<size;++i){
        int a = queue.front();
        if(a < stack.top()){
            return -1;
        }
        stack.push(a);
        queue.pop();
    }

    return 1;
}

int main(){

    std::queue<int> queue;
    int n =0;
    std::cin >> n;
    for(int i =0 ;i<n ;++i){
        int a =0;
        std::cin >> a;
        queue.push(a);
    }
    
    std::cout << is_it_storable(queue) << '\n';

    return 0;
}