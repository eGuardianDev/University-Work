#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

#include "helper.hpp"
#include "algo.hpp"

int main(){

    int n =0;
    std::cin >> n;

    int size = 2*n+1;
    vector<int> list(size,0);

    populate(list);
    print(list);

    printf("==== Staritng algo ====\n");
    start_dfs(list);
    
    bool solved=  is_list_solved(list);
    cout << "Solved: " << std::boolalpha << solved << endl;

    return 0;
}