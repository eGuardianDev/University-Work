#include <iostream>
#include <queue>


template<class DataType>
class stack{

std::queue<DataType> queue;
std::queue<DataType> temp;

public:

    void push(const DataType& element){
        while(!queue.empty())
        {
            temp.push(queue.front());
            queue.pop();
        }
        queue.push(element);
        while(!temp.empty())
        {
            queue.push(temp.front());
            temp.pop();
        }
    }

    void pop(){
        queue.pop();
    }
    const DataType& top(){
        return queue.front();
    }
    bool isEmpty(){
        return queue.empty();
    }


};


int main(){

    stack<int> a;

    a.push(1);
    a.push(2);

    std::cout  << a.top() << " ";
    a.pop();
    std::cout  << a.top();
    a.pop();

    return 0;
}   