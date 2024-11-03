#include <cstddef>
#include <iostream>
#include <stack>

// ~   униерен
// & | бинарен

//Shunting Yard Algorithm

bool Calculator(std::string data){
    std::stack<char> stOp;
    std::stack<bool> stC;
    bool final;
    int len = data.length();
    for(int i = 0;i<len;i++){
        switch(data[i]){
            case '~':
            case '&':
            case '|':
                stOp.push(data[i]);
            break;
            case '0':
            case '1':
                stC.push(bool(data[i] -'0'));
            break;
            case ')':
                char opTop = stOp.top();
                stOp.pop();
                bool temp, temp2; 
                switch(opTop){
                    case '~':
                        temp = stC.top();
                        stC.pop();
                        temp = !temp;
                        
                        stC.push(temp);
                        break;
                    case '&':
                        temp = stC.top();
                        stC.pop();
                        temp2 = stC.top();
                        stC.pop();
                        stC.push(temp && temp2);
                        break;
                    case '|':
                        temp = stC.top();
                        stC.pop();
                        temp2 = stC.top();
                        stC.pop();
                        stC.push(temp || temp2);
                        break;
                }

            break;
        }
    }
    final = stC.top();
    stC.pop();
    if(stOp.size() >0 || stC.size() >0){
        std::cout << "Didn't use all the symbols, Check syntax\n";
    }
    return final;
}


int main(){

    std::string data;
    std::cin >> data;


    std::cout << Calculator(data) << "\n";

    return 0;
}