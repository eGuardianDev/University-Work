#include <iostream>
using namespace std;

int _size = 0;
bool duplicates(long *pointers[]){  
    for(int i =0 ;i < _size;i++){
        for(int j = i; j <_size; j++){
            if(*pointers[i] == *pointers[j]){
                return true;
            }
        }
    }
     return false;
 }

int main()
{
    std::cin >> _size;
    long variables[_size] = {0}; 
    long * pointers[_size] = {0};
    for(int i=0 ;i < _size;i++){
        pointers[i] = new long;
        std::cin >> *pointers[i];
        
    }
    // for(int i =0 ;i < size; i++){
    //    std::cout << pointers[i];
    // }   
    
    bool flag = duplicates(pointers);    

    std::cout << flag;

    for(int i= 0; i< _size; i ++){
        delete pointers[i];
    }
    //delete variables;

    return 0;
}
