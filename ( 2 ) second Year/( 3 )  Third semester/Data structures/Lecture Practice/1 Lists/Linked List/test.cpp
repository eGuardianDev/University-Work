#include "sortedList.hpp"
#include <iostream>



int main(){

    SortedList<int> list;


    list.add(4);
    list.add(3);
    list.add(1);
    std::cout << list.find(4) << " ";
    std::cout <<list.getSize()  << " ";

    list.remove(0);
    std::cout <<list.getSize();

    return 0;
}