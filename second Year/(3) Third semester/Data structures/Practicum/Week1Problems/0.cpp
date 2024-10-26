#include <iostream>

int returnElement(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;

    return 3* returnElement(n-1) * returnElement(n-2) + returnElement(n-3);
}

int main(){
    std::cout << "\n Selectr element to Return: ";
    unsigned int n = 0;
    std::cin >> n;
    std::cout << returnElement(n);


    return 0;
}