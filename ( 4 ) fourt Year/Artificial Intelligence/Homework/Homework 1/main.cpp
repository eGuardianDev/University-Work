#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

#include <chrono>

#include "helper.hpp"
#include "algo_opt.hpp"

int main(){

    int n =0;
    std::cin >> n;

    int size = 2*n+1;
    vector<short> list(size,0);
    
    populate(list);
    
    start_dfs(list);
    
    return 0;
}
