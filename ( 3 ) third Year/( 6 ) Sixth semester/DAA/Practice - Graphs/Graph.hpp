#ifndef GRAPH_FILE
#define GRAPH_FILE

#include <utility>
#include <vector>
using namespace std;

// Graph 1: linear chain 0→1→2→3, plus shortcut 0→3
// {neighbor, weight}
vector<vector<pair<int,int>>> graph1 = {
    {{1, 4}, {3, 10}},  // 0
    {{2, 2}},           // 1
    {{3, 7}},           // 2
    {}                  // 3
};

// Graph 2: diamond 0→{1,2}→3, with back-edge 3→1
vector<vector<pair<int,int>>> graph2 = {
    {{1, 5}, {2, 8}},   // 0
    {{3, 3}},           // 1
    {{3, 6}},           // 2
    {{1, 2}}            // 3  (back-edge, dashed)
};

// Graph 3: 5-node general graph
vector<vector<pair<int,int>>> graph3 = {
    {{1, 1}, {3, 9}},   // 0
    {{2, 4}, {3, 7}},   // 1
    {{3, 3}},           // 2
    {{4, 2}},           // 3
    {{0, 6}}            // 4
};


#endif // GRAPH_FILE