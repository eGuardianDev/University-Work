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
    // print(list);

    // printf("==== Staritng algo ====\n");
        // auto start = chrono::steady_clock::now();
    start_dfs(list);
        // auto end = chrono::steady_clock::now();


    // auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // cout << "Time: " << duration.count() << " us\n";
    // bool solved=  is_list_solved(list);
    // cout << "Solved: " << std::boolalpha << solved << endl;

    return 0;
}
