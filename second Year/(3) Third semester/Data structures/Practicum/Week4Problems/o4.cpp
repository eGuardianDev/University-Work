#include <iostream>
#include <stack>
#include <vector>

bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
    std::stack<int> stack;
    int index =0;
    int mainindex =0;
    
    bool moved= false;
    while(mainindex < pushed.size()){
        if(!moved){
            stack.push(pushed[mainindex]);
        }else moved = false;
        
        if(pushed[mainindex] == popped[index])
        {
            stack.pop();
            index++;
            moved = true;
            mainindex--;
        }
        mainindex++;
    }
    bool flag = true;
    while(index != popped.size()){
        if(stack.top() == popped[index]){
            stack.pop();
        }else {
            flag = false;
        }
        index++;
    }
    if(stack.empty()) return 1;
    
    return 0;
}

int main(){

    int n = 0;
    std::cin >> n;
    std::vector<int> pushed;
    std::vector<int> popped;
    int x;
    for(int i =0 ;i<n;i++){
        std::cin >> x;
        pushed.push_back(x);   
    }for(int i =0 ;i<n;i++){
        std::cin >> x;
        popped.push_back(x);
        
    }

    std::cout << validateStackSequences(pushed, popped) << "\n"; 
    return 0;
}