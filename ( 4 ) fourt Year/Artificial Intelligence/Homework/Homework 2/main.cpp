
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

#include <tuple>
inline int inversions(std::vector<int> &board, const int &n) {
  int inversions = 0;

  for (int i = 0; i < n * n; ++i) {
    for (int j = i + 1; j < n * n; ++j) {
      if (board[i] > board[j] && board[i] != 0 && board[j] != 0) {
        ++inversions;
      }
    }
  }
  return inversions;
}

inline bool duplications(std::vector<int> &board, const int &n) {

  for (int i = 0; i < n * n; ++i) {
    for (int j = i + 1; j < n * n; ++j) {
      if (board[i] == board[j]) {
        return true;
      }
    }
  }

  return false;
}

inline int heuristic_positioned(std::vector<int> &board, const int &n,
                                const int &zero_pos) {
  int solutions = 0;
  int check = 1;

  for (int i = 0; i < n * n; ++i) {
    if (i != zero_pos && board[i] == check) {
      ++solutions;
    } else if (i == zero_pos && board[i] == 0) {
      ++solutions;
    }
    ++check;
  }

  return solutions;
}

std::vector<int> path();

inline int target_pos(const int &index, const int &zero) {
  return (index > zero) ? index + 1 : index;
}

// inline int heuristic_stara_zagora(std::vector<int> &board,
//                                   const int &zero_pos) {
//   int sum = 0;

//   int n = std::sqrt(board.size());

//   for (int i = 0; i < n * n; ++i) {
//     if (board[i] == 0)
//       continue;
//     int target = target_pos(board[i], zero_pos);

//     // stara zagora distance
//     sum += std::abs(i / n - target / n) + std::abs(i % n - target % n);
//   }

//   return sum;
// }

inline void print_board(std::vector<int> &board, const int &n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << board[j + i * n] << " ";
    }
    std::cout << std::endl;
  }
}

inline bool solved(std::vector<int> &board, const int &n, const int &zero_pos) {

  int count = 1;
  for (int i = 0; i < n * n; ++i) {
    if (i == zero_pos) {
      if (board[i] != 0)
        return false;
      continue;
    }
    if (count != board[i]) {
      return false;
    }
    ++count;
  }
  return true;
}

int bound = 0;

// actually dfs for now
// bool ida_star(int * matrix, const int &n, const int &index_zero, const int
// &zero_pos, const int& last_move){

//     // int heuristic = heuristic_stara_zagora(matirx, n, zero_pos);

//     if(heuristic > bound) return heuristic;

//     // if(solved(matrix,n,zero_pos)) return true;

//     int x[4] = {0,0,-1,1};
//     int y[4] = {1,-1,0,0};

//     for(int i =0;i<4;++i){

//         if (last_move != -1 && i == (last_move ^ 1)) continue;

//         int curr_x = index_zero % n;
//         int curr_y = index_zero / n;

//         curr_x +=x[i];
//         curr_y +=y[i];

//         if(curr_x >= n || curr_x <0) continue;
//         if(curr_y >= n || curr_y <0) continue;

//         int new_index = curr_x + curr_y * n;

//         std::swap(matrix[new_index], matrix[index_zero]);

//         path.push_back(i);

//         // if(ida_star(matrix,n,new_index, zero_pos, i)){
//         //     std::cout << "===" << std::endl;
//         //     print_matrix(matrix,n);
//         //     std::cout << "===" << std::endl;
//         //     std::swap(matrix[new_index], matrix[index_zero]);
//         //     return true;
//         // }

//         path.pop();

//         std::swap(matrix[new_index], matrix[index_zero]);
//     }

//     return false;

// }

// heuristic, list, last_move
using Node = std::tuple<int, std::vector<int>, int>;

auto cmp = [](const Node &a, const Node &b) {
  return std::get<0>(a) > std::get<0>(b); // note: > gives min-heap
};

int max_heuristic = 0;

int d_x[4] = {0, 0, 1, -1};
int d_y[4] = {1, -1, 0, 0};

// right now is a*
bool ida_star(std::vector<int> board_t, const int last_move_t,
              const int &zero_pos, int depth) {

  if (solved(board_t, std::sqrt(board_t.size()), zero_pos)) {
    return true;
  }

  std::priority_queue<Node, std::vector<Node>, decltype(cmp)> queue(cmp);

  queue.push(
      // {heuristic_stara_zagora(board, zero_pos) + depth, board, last_move});
      {depth, board_t, last_move_t});

  Node curr = queue.top();
  auto [heuristic, board, last_move] = queue.top();

  // if (solved(board, std::sqrt(board.size()), zero_pos)) {
  //   return true;
  // }

  queue.pop();

  int n = std::sqrt(board.size());
  for (int i = 0; i < 4; ++i) {

    if (last_move != -1 && i == (last_move ^ 1))
      continue;

    int curr_x = zero_pos % n;
    int curr_y = zero_pos / n;

    curr_x += d_x[i];
    curr_y += d_y[i];

    if (curr_x >= n || curr_x < 0)
      continue;
    if (curr_y >= n || curr_y < 0)
      continue;

    int new_index = curr_x + curr_y * n;

    std::swap(board[new_index], board[zero_pos]);
    // queue.push({heuristic_stara_zagora(board, zero_pos) + depth + 1, board,
    // i});
    queue.push({depth + 1, board, i});
    std::swap(board[new_index], board[zero_pos]);
  }

  while (!queue.empty()) {
    auto [heuristic, board, last_move] = queue.top();
    queue.pop();

    // if (heuristic_stara_zagora(board, zero_pos) == 0) {
    //   return true;
    // }

    // if (heuristic > max_heuristic) {
    //   max_heuristic = heuristic;
    // }

    if (ida_star(board, last_move, zero_pos, depth + 1)) {
      return true;
    }
  }

  // queue = std::priority_queue<Node>();
  return false;
}

bool start_ida_star(std::vector<int> board, const int &zero_pos) {

  // queue = std::priority_queue<Node>(); // clears the queue
  // max_heuristic = 100;
  return ida_star(board, -1, zero_pos, 0);
}

int main() {

  int size = 0;
  std::cin >> size;

  ++size;

  int n = std::sqrt(size);

  if (size <= 1 || n * n != size) {
    std::cout << "Invalid count of elements" << std::endl;
    return 1;
  }

  int zero_pos = -1;

  std::cin >> zero_pos;

  if (zero_pos < -1 || zero_pos >= size) {
    std::cout << "zero out of bound selection" << std::endl;
    return 4;
  }
  if (zero_pos == -1) {
    zero_pos = n * n - 1;
  }

  std::vector<int> board;
  for (int i = 0; i < size; ++i) {
    int temp = 0;
    std::cin >> temp;
    board.push_back(temp);
  }

  // check if solvable
  {
    // int _inversions = inversions(board, n);
    // if (_inversions % 2 != 0) {
    //   std::cout << "Not solvable due to Inversions - " << _inversions
    //             << std::endl;
    //   return 2;
    // }
    if (duplications(board, n)) {
      std::cout << "Duplicates in the boxes" << std::endl;
      return 3;
    }

    int i = 0;
    for (i = 0; i < board.size(); ++i) {
      if (board[i] == 0)
        break;
    }
    if (i == board.size()) {
      std::cout << "Zero is missing" << std::endl;
      return 4;
    }
  }

  int zero_start = 0;
  for (int i = 0; i < size; ++i) {
    if (board[i] == 0) {
      zero_start = i;
    }
  }

  if (start_ida_star(board, zero_pos)) {
    std::cout << "Solved" << std::endl;
  } else {
    std::cout << "Not Solved" << std::endl;
  }

  print_board(board, n);

  return 0;
}