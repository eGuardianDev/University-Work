#include <climits>
#include <iostream>
#include <vector>

void print(const std::vector<int> &board) {

  std::cout << "+---+---+---+\n";
  for (int i = 0; i < board.size(); ++i) {
    std::cout << "| ";
    if (board[i] == 1) {
      std::cout << "X";
    } else if (board[i] == 2) {
      std::cout << "O";
    } else {
      std::cout << "_";
    }
    std::cout << " ";

    if ((i + 1) % 3 == 0) {
      std::cout << "|" << std::endl;
      std::cout << "+---+---+---+\n";
    }
  }
}
void print_raw(const std::vector<int> &board) {

  std::cout << "+---+---+---+\n";
  for (int i = 0; i < board.size(); ++i) {
    std::cout << "| ";
    if (board[i] == 1) {
      std::cout << 1;
    } else if (board[i] == 2) {
      std::cout << 2;
    } else {
      std::cout << 0;
    }
    std::cout << " ";

    if ((i + 1) % 3 == 0) {
      std::cout << "|" << std::endl;
      std::cout << "+---+---+---+\n";
    }
  }
}

inline int solved(std::vector<int> &board) {
  for (int i = 0; i < 3; ++i) {
    int r = board[i * 3];
    if (r != 0 && r == board[i * 3 + 1] && r == board[i * 3 + 2]) {
      return r == 1 ? 1 : -1;
    }

    int c = board[i];
    if (c != 0 && c == board[3 + i] && c == board[6 + i]) {
      return c == 1 ? 1 : -1;
    }
  }
  if (board[0] == board[4] && board[4] == board[8] && board[8] != 0) {
    return board[0] == 1 ? 1 : -1;
  }
  if (board[2] == board[4] && board[4] == board[6] && board[6] != 0) {
    return board[2] == 1 ? 1 : -1;
  }

  for (auto a : board) {
    if (a == 0)
      return 2;
  }
  return 0;
}

int minimax(std::vector<int> &board, bool min, int alpha, int beta) {

  int s = solved(board);
  if (s != 2) {
    return s;
  }

  if (min) {
    int minimal = INT_MAX;
    for (int i = 0; i < 9; ++i) {
      if (board[i] != 0)
        continue;
      board[i] = 2;
      minimal = std::min(minimal, minimax(board, !min, alpha, beta));
      board[i] = 0;
    }
    return minimal;
  } else { // max
    int maximum = INT_MIN;
    for (int i = 0; i < 9; ++i) {
      if (board[i] != 0)
        continue;
      board[i] = 1;
      maximum = std::max(maximum, minimax(board, !min, alpha, beta));
      board[i] = 0;
    }
    return maximum;
  }
}

int start_algo(std::vector<int> &board) {
  int index = -1;
  int best = INT_MAX;
  for (int i = 0; i < 9; ++i) {
    if (board[i] != 0)
      continue;
    board[i] = 2;
    int m = minimax(board, false, INT_MAX, INT_MIN);
    board[i] = 0;
    if (best > m) {
      best = m;
      index = i;
    }
  }
  return index;
}

int main() {

  std::string type;
  std::getline(std::cin, type);

  // std::string delimiter = " ";
  // std::string token = s.substr(0, s.find(delimiter)); // token is "scott"
  std::vector<int> board(9, 0);

  if (type == "JUDGE") {
    std::string turn;
    std::getline(std::cin, turn);

    int count = 0;
    for (int i = 0; i < 6; ++i) {
      std::string line;
      std::getline(std::cin, line);
      if (i % 2 == 0) {
        for (int j = 0; j < line.size(); ++j) {
          if (line[j] == '_') {
            board[count++] = 0;
          } else if (line[j] == 'X') {
            board[count++] = 1;
          } else if (line[j] == 'O') {
            board[count++] = 2;
          }
        }
      }
    }
    print(board);
  } else if (type == "GAME") {

    int match = 0;
    int game = 0;
    while ((game = solved(board)) == 2) {

      match++;

      if (match % 2 == 0) {
        int r, c;
        while (true) {
          std::cin >> r >> c;
          if (r < 1 || r > 3)
            continue;
          if (c < 1 || c > 3)
            continue;
          r -= 1;
          c -= 1;
          if (board[r * 3 + c]) {
            continue;
          }
          break;
        }
        board[r * 3 + c] = 1;
      } else {
        int inde = start_algo(board);
        board[inde] = 2;
      }

      print(board);
    }
    switch (game) {
    case 0:
      std::cout << "Draw" << std::endl;
      break;
    case 1:
      std::cout << "Win X" << std::endl;
      break;
    case -1:
      std::cout << "Win O" << std::endl;
      break;
    }
    print_raw(board);
  }

  return 0;
}