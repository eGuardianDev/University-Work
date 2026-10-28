
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

#include <tuple>

#include "algo.hpp"

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