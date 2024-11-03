#include <cstdint>
#include <iostream>
#include <vector>


int main(){
    std::cout << "hello wrold \n";
    std::vector<uint8_t> tester;
    tester.push_back(3);
    std::cout << bool((*tester.data() & (1 << 2))>> 2);
    return 0;
}