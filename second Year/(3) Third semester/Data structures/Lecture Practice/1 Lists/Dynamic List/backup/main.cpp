

#include <iostream>
#include "dynamicList.hpp"
int main(){

    DynamicList<int> list(4);

    list.append(1);

    std::cout << list[0];

    return 0;
}