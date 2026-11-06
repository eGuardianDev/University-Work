#include <climits>
#include <iostream>
#include <vector>

enum Place : short { X = 1, O = 2 };

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

int minimax(std::vector<int> &board, int me, bool min, int alpha, int beta,
            int depth) {

  int other = (me == 2) ? 1 : 2;
  int s = solved(board);
  if (s != 2) {
    s *= (10 - depth);
    return me == 1 ? s : -s;
  }

  const int order[9] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

  if (min) {
    int minimal = INT_MAX;
    for (int j = 0; j < 9; ++j) {
      int i = order[j];
      if (board[i] != 0)
        continue;
      board[i] = other;
      minimal =
          std::min(minimal, minimax(board, me, !min, alpha, beta, depth + 1));
      board[i] = 0;

      if (minimal <= alpha)
        return minimal;
      beta = std::min(minimal, beta);
    }
    return minimal;
  } else { // max
    int maximum = INT_MIN;
    for (int j = 0; j < 9; ++j) {
      int i = order[j];
      if (board[i] != 0)
        continue;
      board[i] = me;
      maximum =
          std::max(maximum, minimax(board, me, !min, alpha, beta, depth + 1));
      board[i] = 0;

      if (maximum >= beta)
        return maximum;
      alpha = std::max(maximum, alpha);
    }
    return maximum;
  }
}

int start_algo(std::vector<int> &board, char turn) {
  int me = 1; // x
  if (turn == 'O') {
    me = 2; // O
  }
  const int order[9] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

  int index = -1;
  int best = INT_MIN;
  for (int j = 0; j < 9; ++j) {
    int i = order[j];
    if (board[i] != 0)
      continue;
    board[i] = me;
    int m = minimax(board, me, true, INT_MIN, INT_MAX, 1);
    board[i] = 0;
    if (best < m) {
      best = m;
      index = i;
    }
  }
  return index;
}

void JUDGE_play() {

  std::vector<int> board(9, 0);
  std::string turn;
  std::getline(std::cin, turn);

  char turn_type = '0';
  for (int i = 0; i < turn.size(); ++i) {
    if (turn[i] == 'X' || turn[i] == 'O') {
      turn_type = turn[i];
      break;
    }
  }

  if (turn_type == '0')
    return;

  int count = 0;
  for (int i = 0; i < 7; ++i) {
    std::string line;
    std::getline(std::cin, line);
    if (i % 2 == 1) {
      for (int j = 0; j < line.size(); ++j) {
        if (line[j] == '_') {
          board[count++] = 0;
        } else if (line[j] == 'X') {
          board[count++] = Place::X;
        } else if (line[j] == 'O') {
          board[count++] = Place::O;
        }
      }
    }
  }

  if (solved(board) != 2) {
    std::cout << -1 << std::endl;
    return;
  }

  int index = start_algo(board, turn_type);
  std::cout << (index / 3) + 1 << " " << (index % 3) + 1 << std::endl;
}

void GAME_play() {
  std::vector<int> board(9, 0);

  std::string first;
  std::getline(std::cin, first);

  char first_type = '0';
  for (int i = 0; i < first.size(); ++i) {
    if (first[i] == 'X' || first[i] == 'O') {
      first_type = first[i];
      break;
    }
  }

  std::string human;
  std::getline(std::cin, human);

  char human_type = '0';
  for (int i = 0; i < human.size(); ++i) {
    if (human[i] == 'X' || human[i] == 'O') {
      human_type = human[i];
      break;
    }
  }

  bool human_turn = (human_type == first_type);
  int game = 0;

  while ((game = solved(board)) == 2) {
    if (human_turn == true) {
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
      if (human_type == 'X') {
        board[r * 3 + c] = Place::X;
      } else {
        board[r * 3 + c] = Place::O;
      }
      human_turn = false;
    } else {

      int inde = 0;

      if (human_type == 'X') {
        inde = start_algo(board, 'O');
        board[inde] = Place::O;
      } else {
        inde = start_algo(board, 'X');
        board[inde] = Place::X;
      }
      human_turn = true;
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

int main() {

  std::string type;
  std::getline(std::cin, type);

  if (!type.empty() && type.back() == '\r')
    type.pop_back();

  if (type == "JUDGE") {
    JUDGE_play();
  } else if (type == "GAME") {
    GAME_play();
  }

  return 0;
}