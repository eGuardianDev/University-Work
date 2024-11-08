#include <iostream>
#include <stack>



template<class DataType>
class queue{

    std::stack<DataType> stack;
    std::stack<DataType> temp;

public:

    bool isEmpty(){
        return stack.empty();
    }
    void push(const DataType& element){

        while(!stack.empty()){
            temp.push(stack.top());
            stack.pop();
        }

        stack.push(element);

        while(!temp.empty()){
            stack.push(temp.top());
            temp.pop();
        }
    }

    void pop()
    {
        stack.pop();
    }

    const DataType& front() const{
        return stack.top();
    }

};




int main(){

    queue<int> a;
    
    a.push(1);
    std::cout << a.front();
    std::cout << a.isEmpty();
    a.pop();
    std::cout << a.isEmpty();


}