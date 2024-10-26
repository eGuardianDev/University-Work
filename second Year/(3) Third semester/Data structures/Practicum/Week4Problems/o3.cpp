#include <iostream>
#include <stack>


int main(){

    int n =0;
    std::cin >> n;

    int cmd;
    std::stack<int> stack;
    while(n!=0){
        std::cin >> cmd;
        switch(cmd ){
            case 1:
                int data;
                std::cin >> data;
                stack.push(data);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                std::stack<int> temp;
                int a = stack.top();
                stack.pop();
                temp.push(a);
                while(!stack.empty()){
                    if(a < stack.top()){
                        a = stack.top();
                        temp.push(a);
                    }else temp.push(stack.top());
                    stack.pop();
                }
                std::cout << a << '\n';

                while(!temp.empty()){
                    stack.push((temp.top()));
                    temp.pop();
                }

                break;
        }
        n--;

    }

    return 0;
}