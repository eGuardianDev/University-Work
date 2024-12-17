#include <iostream>


void function(int& a){
    a = 10;
}

void addressOfCopy(int a){
    std::cout << "address of copy: " << &a << std::endl;
}
void addressOfReferences(int& a){
    std::cout << "address of reference: "<< &a << std::endl;
}


int SumReferences(int& a, int& b){
    a += b;
    b = 5;
    return a;
}
int SumCopy(int a, int b){
    a += b;
    b = 5;
    return a;
}
int SumOptimized(int a, const int& b){
    a += b;
    // b = 5; // ! error
    return a;
}
int SumOptimized2(const int* &a, const int& b){
    int res = 0;
    res = *a + b;
    return res;
    // return a+b; 
}


// Stack
// bool isEmpty(){
//     return size == 0;
// }


int main(){

    int a = 0, b = 0, res = 0;
    std::cout << a << "\n";
    function(a);
    std::cout << a << "\n\n";

    addressOfCopy(a);
    addressOfReferences(a);
    std::cout << "Address of original: " << &a << std::endl;

    std::cout << "\n\n";

    a =1;
    b = 2;
    res = SumReferences(a, b);
    std::cout <<"after sum with reference: \n";
    std::cout << "a " <<  a << "\n";
    std::cout << "b " <<  b << "\n";
    std::cout << "result " <<  res << "\n\n";
    
    a =1;
    b = 2;
    res = SumCopy(a, b);
    std::cout <<"after sum with copy: \n";
    std::cout << "a " <<  a << "\n";
    std::cout << "b " <<  b << "\n";
    std::cout << "result " <<  res << "\n\n";
    
    a = 1;
    b = 2;
    res = SumOptimized(a, b);
    std::cout <<"after sum with optimization: \n";
    std::cout << "a " <<  a << "\n";
    std::cout << "b " <<  b << "\n";
    std::cout << "result " <<  res << "\n\n";
       
    const int *point = new int(1);
    b = 2;
    res = SumOptimized2(point, b);
    std::cout <<"after sum with optimization 2: \n";
    std::cout << "a " <<  a << "\n";
    std::cout << "b " <<  b << "\n";
    std::cout << "result " <<  res << "\n\n";
    
    return 0;
}