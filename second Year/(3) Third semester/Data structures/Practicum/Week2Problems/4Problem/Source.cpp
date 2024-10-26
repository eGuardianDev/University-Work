#include <bitset>
#include <cassert>
#include <iostream>

const unsigned int Max_N = 99;

std::bitset<Max_N> b1Set;
std::bitset<Max_N> b2Set;

int main(){


    unsigned int m1,m2,n;
    std::cin >> n>>m1>>m2;
    
    assert(m1 <=Max_N && m2 <=Max_N);
    assert(m1 <= n && m2 <=n);

    std::cout << " first firend: \n";
    for(int i =0; i<m1;i++){
        int a =0;
        std::cin >> a;
        b1Set[a] = 1;
    }
    std::cout << " second firend: \n";
    for(int i =0; i<m2;i++){
        int a =0;
        std::cin >> a;
        b2Set[a] = 1;
    }
    
    b1Set &= b2Set;
    std::cout << b1Set.count();
    return 0;
}