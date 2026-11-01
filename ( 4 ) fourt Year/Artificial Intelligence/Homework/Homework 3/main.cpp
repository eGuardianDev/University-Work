#include <iostream>

#include <cstdint>
#include <vector>
#include <climits>


uint32_t SEED = 123;

int32_t xorshift32(const int32_t seed){

    uint32_t x = seed & 0xFFFFFFFF;

    x ^= (x << 13) & 0xFFFFFFFF;
    x ^= x >> 17;
    x ^= (x << 5) & 0xFFFFFFFF;

    return x & 0xFFFFFFFF;
}

int32_t int_range(int l, int h){
    SEED = xorshift32(SEED);
    return (SEED % h) + l;
}

//x,y
std::vector<std::pair<int,int>> queens;

std::vector<int> rows;
std::vector<int> diagonal1;
std::vector<int> diagonal2;

void init(const int &n){

    if(queens.size() > 0){
        rows.clear();
        diagonal1.clear();
        diagonal2.clear();
        queens.clear();
    }
    
    rows.resize(n);
    diagonal1.resize(n*2-1);
    diagonal2.resize(n*2-1);
    
    for(int i =0;i<n;++i){
        int r = int_range(0, n);
        queens.push_back({r,i});
        
        int o_r = r;
        int o_c = i;
        
        int o_d1 = (o_c + o_r);
        int o_d2 = (o_c - o_r + n -1);
        
        rows[r]++;
        diagonal1[o_d1]++;
        diagonal2[o_d2]++;
    }
    
}

void print_board(){
    int n = queens.size();
    std::vector<std::vector<bool>> board(n, std::vector<bool>(n,false));
    for(int i=0;i<queens.size();++i){
        board[queens[i].first][queens[i].second] = true;
    }
    for(int i =0;i<board.size();++i){
        for(int j =0;j<board[i].size();++j){
            std::cout << (board[j][i] ? "*" : ".");
        }
        std::cout << std::endl;
    }
}
void print_queens(){
    int n = queens.size();
    std::vector<int> qe(n,0);
    for(int i=0;i<queens.size();++i){

        qe[queens[i].first] = queens[i].second;
    }

    std::cout << '[';
    for(int i =0;i<qe.size();++i){
        std::cout << qe[i];
        if(i != qe.size()-1){
            std::cout << ", ";
        }
    }
    std::cout << ']' << std::endl;
}

inline int conflicts_rows(){
    int n = 0;

    for(auto row : rows){
        if(row > 1){
            n += 1;
        }
    }

    return n;
}

inline int conflict_diagonal1(){
    int n =0;

    for(auto dia : diagonal1){
          if(dia > 1){
            n += 1;
        }
    }
    return n;
}

inline int conflict_diagonal2(){
    int n =0;

    for(auto dia : diagonal2){
          if(dia > 1){
            n += 1;
        }
    }
    return n;
}

const int MAX_ITERATIONS = 500000;

bool algorithm(){

    int n = queens.size();
    int iterations = 0;
    while(conflicts_rows() > 0 || conflict_diagonal1() > 0 || conflict_diagonal2() > 0){
        ++iterations;
        if(iterations >= MAX_ITERATIONS){
            return false;
        }

        int queen_index = int_range(0,n);

        ++iterations;
        // selecting row

        int min_conflict_index = -1;
        int min_conflict_dia1_index = -1;
        int min_conflict_dia2_index = -1;
        int min_conflict = INT_MAX;
        
        int o_r = queens[queen_index].first;
        int o_c = queens[queen_index].second;

        int o_d1 = (o_c + o_r) ;
        int o_d2 = (o_c - o_r + n - 1) ;
        if(rows[o_r] + diagonal1[o_d1] + diagonal2[o_d2] == 3) continue;


        std::vector<int> best;
        for(int i =0;i<n;++i){

            if(i == o_r) continue;

            int dia1 = (i + o_c);
            int dia2 = (o_c - i + n - 1);
            int sum = rows[i] + diagonal1[dia1] + diagonal2[dia2];
            if(min_conflict > sum){
                min_conflict = sum;
                best.clear();
            }
            if(min_conflict == sum){
                best.push_back(i);
            }

        }
        int i = best[int_range(0,best.size())];
        
        
        int dia1 = (i + o_c);
        int dia2 = (o_c - i + n - 1);
        
        min_conflict_index = i; 
        min_conflict_dia1_index = dia1;
        min_conflict_dia2_index = dia2;

        --rows[o_r];
        --diagonal1[o_d1];
        --diagonal2[o_d2];
        queens[queen_index].first = min_conflict_index;
        ++diagonal1[min_conflict_dia1_index];
        ++diagonal2[min_conflict_dia2_index];
        ++rows[min_conflict_index];

        // std::cout << " " << std::endl;
        // print_board();

    }

    // std::cout << "Finished in: " <<  iterations << std::endl;
    return true;
}

    
int main(){
    
    int n =0;
    std::cin >> n;


    if(n == 3 || n ==2){
        std::cout << "-1" << std::endl;
        return 0;
    }
    
    // std::cout << std::endl;
    // for(int i =0;i<n;++i){
    //     for(int j =0;j<n;++j){
    //         std::cout << (i+j) << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // std::cout << std::endl;
    
    // for(int r =0;r<n;++r){
    //     for(int c =0;c<n;++c){
    //         std::cout << (r-c + n -1) << " ";
    //     }
    //     std::cout << std::endl;
    // }
    init(n);
    // print_board();

    while(!algorithm()){
        init(n);
        // std::cout << "Algorithm failed" << std::endl;
    }

    print_queens();
    // std::cout << conflicts_rows() << std::endl;
    // std::cout << conflict_diagonal1() << std::endl;
    // std::cout << conflict_diagonal2() << std::endl;

    return 0;
}
