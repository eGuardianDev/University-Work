#include <iostream>
#include <queue>
#include <stack>


template<class DataType>
void print(std::queue<DataType> &q) {
    int size = q.size();
    for(int i =0;i<size;i++){
        std::cout << q.front() << " ";
        q.pop();
    }
}

template<class DataType>
bool rotate(std::queue<DataType> &q, const int& k){
    std::stack<int> stack;
    int size = q.size();
    if(k > size) return false;
    for(int i =0 ;i<k; ++i){
        stack.push(q.front());
        q.pop();
    }

    for(int i =0;i<k;++i){
        q.push(stack.top());
        stack.pop();
    }
    size-=k;
    for(int i =0 ;i<size;++i){
        q.push((q.front()));
        q.pop();
    }
    return true;
}

int main(){
    
    std::queue<int> queue;

    int n = 0;
    std::cin >> n;
    
    for(int i =0;i<n;++i){
        int a;
        std::cin >> a;
        queue.push(a);
    }

    int k;
    std::cin >> k;
    rotate(queue,k);
    

    print(queue);
    return 0;
}