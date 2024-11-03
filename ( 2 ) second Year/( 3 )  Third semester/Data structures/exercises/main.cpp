#include <iostream>
#include "boolvector.hpp"

int main() {
	BoolVector v(0);
	BoolVector u(0);

    std::string a;
    std::cin >> a;
    bool errorFlag = false;
    bool invalidSymbol = false;
    for(int i =0;i<a.length();i++){
        if(invalidSymbol) {
            std::cout << "invalid symbol in string";
            return 1;
        }
        if(errorFlag) break;

        switch(a[i]){
            case '(':
                u.push_back(true);
                v.push_back(true);
            break;
            case ')':
                if(u.size() !=0 && u[v.size()-1] == true)
                {
                    u.pop_back();
                    v.pop_back();
                }
                else errorFlag = true;
            break;
            case '{':
                u.push_back(false);
                v.push_back(false);
            break;
            case '}':
                if(u.size() !=0 && u[v.size()-1] == false)
                {
                    u.pop_back();
                    v.pop_back();
                }
                else errorFlag = true;
            break;

            //2*

            case '[':
                u.push_back(false);
                v.push_back(false);
            break;
            case ']':
                if(v.size() !=0 && v[v.size()-1] == false)
                {
                    u.pop_back();
                    v.pop_back();
                }
                else errorFlag = true;
            break;
            
            case '<':
                u.push_back(true);
                v.push_back(true);
            break;
            case '>':
                if(v.size() !=0 && v[v.size()-1] == true)
                {
                    u.pop_back();
                    v.pop_back();
                }
                else errorFlag = true;
            break;

            default:
                invalidSymbol = true;                
            break;




        }
    }
    int count = v.size() + u.size();
    if(errorFlag) {
        std::cout << "error brackets not closed";
    }else{
        std::cout << "brackets are closed";
        
    }
	std::cout << std::endl;
}