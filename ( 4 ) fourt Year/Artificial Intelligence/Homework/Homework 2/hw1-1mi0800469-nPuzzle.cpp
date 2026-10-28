
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

int d_x[4] = {0, 0, 1, -1};
int d_y[4] = {1, -1, 0, 0};

inline int target_position(int element, int zero_position) {
  if (element <= zero_position) {
    return (element - 1);
  }
  return element;
}

int heuristic_stara_zagora(const std::vector<int> &board,
                           const int &zero_position) {
  int sum = 0;

  int selection = 0;
  int board_n = std::sqrt(board.size());
  for (int i = 0; i < board.size(); ++i) {

    int element = board[i];

    if (element == 0)
      continue;

    int target_square = target_position(element, zero_position);

    // current
    int c_x = i % board_n;
    int c_y = i / board_n;

    // target
    int t_x = target_square % board_n;
    int t_y = target_square / board_n;

    // it doesn't matter if I got it wrong because at the end it is all computed
    // like this:
    sum += std::abs(c_x - t_x) + std::abs(c_y - t_y);
  }

  return sum;
}

int bound = 0;

std::vector<int> paths;

inline int ida_star(std::vector<int> &board, const int &last_move,
                    const int &final_zero_position,
                    const int &current_zero_position, const int &depth,
                    const int &limit) {

  int h = heuristic_stara_zagora(board, final_zero_position);
  if (h == 0)
    return -1; // done

  int f = h + depth;
  if (f > limit)
    return f; // set to new limit

  int new_limit = INT_MAX;

  int n = std::sqrt(board.size());
  // go to every dir
  for (int i = 0; i < 4; ++i) {
    // skip so that it doesn't go back and forward
    if (last_move != -1 && i == (last_move ^ 1)) {
      continue;
    }

    // compute next move
    int new_x = (current_zero_position % n) + d_x[i];
    int new_y = (current_zero_position / n) + d_y[i];
    if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) {
      continue;
    }
    int new_zero_position = new_y * n + new_x;

    std::swap(board[current_zero_position], board[new_zero_position]);
    paths.push_back(i); // remembers path
    int res = ida_star(board, i, final_zero_position, new_zero_position,
                       depth + 1, limit);

    if (res == -1) {
      return -1;
    }
    new_limit = std::min(new_limit, res);
    paths.pop_back(); // forget last move
    std::swap(board[current_zero_position], board[new_zero_position]);
  }

  return new_limit; // this will be the new limit for the next iteration
}

int start_ida_star(std::vector<int> board, const int &final_zero_position) {

  int limit = heuristic_stara_zagora(board, final_zero_position);

  int zero_curr;
  for (int i = 0; i < board.size(); ++i) {
    if (board[i] == 0) {
      zero_curr = i;
    }
  }

  while (true) {
    int result = ida_star(board, -1, final_zero_position, zero_curr, 0, limit);
    if (result == -1)
      break;
    if (result == INT_MAX)
      return result;
    limit = result;
  }

  return -1;
}

void display_path() {
  std::cout << paths.size() << std::endl;
  for (int i = 0; i < paths.size(); ++i) {
    switch (paths[i]) {
    case 0:
      std::cout << "up" << std::endl;
      break;
    case 1:
      std::cout << "down" << std::endl;
      break;
    case 2:
      std::cout << "left" << std::endl;
      break;
    case 3:
      std::cout << "right" << std::endl;
      break;
    }
  }
}

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

inline void print_board(std::vector<int> &board, const int &n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << board[j + i * n] << " ";
    }
    std::cout << std::endl;
  }
}

inline bool solved(std::vector<int> board, const int zero_position) {

  int count = 1;
  for (int i = 0; i < board.size(); ++i) {

    if (i == zero_position) {
      if (board[i] != 0) {
        return false;
      }
      continue;
    }

    if (count != board[i]) {
      return false;
    }

    ++count;
  }
  return true;
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

  int final_zero_position = -1;

  std::cin >> final_zero_position;

  if (final_zero_position < -1 || final_zero_position >= size) {
    std::cout << "zero out of bound selection" << std::endl;
    return 4;
  }
  if (final_zero_position == -1) {
    final_zero_position = n * n - 1;
  }

  std::vector<int> board;
  for (int i = 0; i < size; ++i) {
    int temp = 0;
    std::cin >> temp;
    board.push_back(temp);
  }

  // check if solvable
  {
    int _inversions = inversions(board, n);
    if (_inversions % 2 != 0) {
      // std::cout << "Not solvable due to Inversions - " << _inversions
      // << std::endl;

      std::cout << "-1" << std::endl;
      return 0;
    }
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

  // std::cout << "Heuristic: "
  //           << heuristic_stara_zagora(board, final_zero_position) <<
  //           std::endl;
  int a = start_ida_star(board, final_zero_position);
  if (a == -1) {
    // std::cout << "Solved" << std::endl;
    display_path();
  } else {
    // std::cout << "Not Solved - " << a << std::endl;
  }

  // print_board(board, n);

  return 0;
}