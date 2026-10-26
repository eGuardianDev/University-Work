
#include <cmath>
#include <iostream>

int inversions(int * matrix, const int& n ){
    int inversions = 0;


    for(int i =0;i<n*n;++i){
        for(int j =i+1; j<n*n;++j){
            if(matrix[i] > matrix[j] && matrix[i] != 0 && matrix[j] != 0){
                ++inversions;
            }
        }   
    }


    return inversions;
}


bool duplications(int * matrix, const int& n ){

    for(int i =0;i<n*n;++i){
        for(int j =i+1; j<n*n;++j){
            if(matrix[i] == matrix[j]){
                return true;
            }
        }   
    }

    return false;
}

int heuristic_positioned(int * matrix, const int& n, const int& zero_pos){
    int solutions = 0;
    int check = 1;
    

    for(int i =0;i<n*n;++i){
        if(i != zero_pos && matrix[i] == check){
            ++solutions;
        }
        else if(i == zero_pos && matrix[i] == 0){
            ++solutions;
        }
        ++check;
    }

    return solutions;
}

// OLD CODE:
// // zero_pos expected to be [0,8] for size 3*3 grid
// inline int heuristic_stara_zagora(int *matrix, const int& n, const int& zero_pos, const int& index){
    
    
//     int r = index / n;
//     int c = index % n;

//     int target = matrix[index];

//     if(target == 0){
//         target = zero_pos;
//     }else{
//         target -=1;
//     }

//     int t_r = target / n;
//     int t_c = target % n;
 

//     return std::abs(r - t_r) + std::abs(c - t_c);
// }


inline int target_pos(const int& index, const int& zero){
    return (index > zero) ? index+1 : index;
}

inline int heuristic_stara_zagora(int *matrix, const int& n, const int& zero_pos, const int& index){
    int sum = 0;

    for(int i =0 ;i<n*n;++i){
        if(matrix[i] == 0) continue;
        int target = target_pos(matrix[i], zero_pos);

        // stara zagora distance
        sum += std::abs(i/n -target/n) + std::abs( i % n - target/n);
    }

    return sum;
}


void print_matrix(const int * matrix, const int &n){
    for(int i =0;i<n;++i){
        for(int j =0; j <n;++j){
            std::cout << matrix[j + i*n] << " ";
        }
        std::cout << std::endl;
    }

}

bool solved(int * matrix, const int &n, const int &zero_pos){

    int count = 1;
    for(int i =0; i < n*n;++i){
        if(i == zero_pos){
            if(matrix[i] != 0) return false;
            continue;
        }
        if(count != matrix[i]){
            return false;
        }
            ++count;
    }
    return true;
}

int steps = 0;

// actually dfs for now
bool ida_star(int * matrix, const int &n, const int &index_zero, const int &zero_pos, const int& last_move){

    steps++;

    if(steps > 50) return true;
    if(solved(matrix,n,zero_pos))
    {
        return true;
    }

    int x[4] = {0,0,-1,1};
    int y[4] = {1,-1,0,0};

    for(int i =0;i<4;++i){

        if (last_move != -1 && i == (last_move ^ 1)) continue; 

        int curr_x = index_zero % n;
        int curr_y = index_zero / n;
        
        curr_x +=x[i];
        curr_y +=y[i];

        if(curr_x >= n || curr_x <0) continue;
        if(curr_y >= n || curr_y <0) continue;

        int new_index = curr_x + curr_y * n; 

        std::swap(matrix[new_index], matrix[index_zero]);

        if(ida_star(matrix,n,new_index, zero_pos, i)){
            std::cout << "===" << std::endl;
            print_matrix(matrix,n);
            std::cout << "===" << std::endl;
            std::swap(matrix[new_index], matrix[index_zero]);
            return true;
        }

        std::swap(matrix[new_index], matrix[index_zero]);
    }

    return false;

}

int main(){
     
    int size = 0;
    std::cin >> size; 
    
    ++size;

    int n = std::sqrt(size);
    
    if(size <= 1 || n * n != size ){
        std::cout << "Invalid count of elements" << std::endl;
        return 1;
    }

    int zero_pos = -1;

    std::cin >> zero_pos;

    if(zero_pos < -1 || zero_pos >= size){
        std::cout << "zero out of bound selection" << std::endl;
        return 4;
    }
     if(zero_pos == -1){
        zero_pos = n*n-1;
    }

    int * matrix = new int[size];

    for (int i =0;i<size;++i){
        std::cin >> matrix[i];
    }

    {
        int _inversions = inversions(matrix,n);
        if( _inversions % 2 != 0){
            std::cout << "Not solvable due to Inversions - " <<  _inversions << std::endl;
            return 2;
        }
    }

    {
        if(duplications(matrix,n)){
            std::cout << "Duplicates in the boxes" << std::endl;
            return 3;
        }
    }

    int zero =0;
    for(int i =0;i<size;++i){
        if(matrix[i] == 0){
            zero = i;
        }
    }

    ida_star(matrix,n,zero, zero_pos, -1);

    print_matrix(matrix,n);

    // std::cout << "Solved: " <<  heuristic_positioned(matrix,n,zero_pos) << "/" << size << std::endl;
    
    // std::cout << "is Solved: " <<  solved(matrix,n,zero_pos) << std::endl;


    // for(int i =0;i<n;++i){
    //     for(int j =0; j <n;++j){
    //         std::cout << heuristic_stara_zagora(matrix,n,zero_pos,j+i*n) << " ";
    //     }
    //     std::cout << std::endl;
    // }

    delete [] matrix;
    return 0;
}