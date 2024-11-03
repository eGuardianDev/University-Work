#include <iostream>
#include <stack>


//const for not changing
//& to not copy
bool Palindrome(const std::string & string){ 

    std::stack<char> half;
    int stringLen = string.length();
    for(int i = 0;i < stringLen/2;i++){
        half.push(string[i]);
    } 
    
    int startingFrom = stringLen/2;
    if(stringLen % 2 != 0)startingFrom += 1;

    for(int i = startingFrom;i < stringLen;i++){
        if(!half.empty() && half.top() == string[i]) half.pop();
        else return false;
    }  
    return true;
}


int main(){

    std::string data;
    std::cin >> data;

    std::cout << Palindrome(data) << std::endl;

    return 0;
}