

#include <ios>
#include <iostream>
#include "dynamicList.hpp"
int main(){

    DynamicList<int> list(4);
    std::cout <<"isEmpty at start : " << std::boolalpha<< list.isEmpty()<< "\n";

    list.append(1);
    
    list.append(2);
    list.append(3);
    list.append(4);
    
    list.remove(0);
    std::cout <<"isEmpty at end : " << std::boolalpha<< list.isEmpty()<< "\n";
    
    DynamicList<int> list4e(1);
    list4e.append(2);
    list4e.append(3);
    // list = list4e;
    DynamicList<int> list2(list4e);
    std::cout << list2.getSize();
    std::cout << list4e.getSize();
    // std::cout << list4e.contains(2) << "\n";
    // std::cout <<"First element: "<< list.get(2)<< "\n";
    // std::cout <<"Capacity :" << list.getCapacity() << " \n";
    // std::cout <<"Size: " << list.getSize() << "\n";
    
    
    return 0;
}