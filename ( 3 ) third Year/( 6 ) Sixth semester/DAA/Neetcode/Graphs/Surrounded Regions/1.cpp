

#include <iostream>
#include <set>
#include <vector>

using namespace std;


// surrounded
void dfs(vector<vector<char>> &board, int r,int c){

    if(r <0 || c <0 || r>=board.size() || c>= board[r].size()) return;

    if(board[r][c] != 'O') return;
    board[r][c] = 'S';
    dfs(board,r+1,c);
    dfs(board,r-1,c);
    dfs(board,r,c+1);
    dfs(board,r,c-1);

}

void solve(vector<vector<char>>& board) {

    int rows = board.size();
    int cols = board[0].size();
    for(int r= 0; r<board.size();++r){
        set<pair<int,int>> visited;
        for(int c=0; c<board[r].size();++c){
            if ((r == 0 || r == rows-1 || c == 0 || c == cols-1) && board[r][c] == 'O')
                dfs(board, r, c);

        }
    }
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            board[r][c] = (board[r][c] == 'S') ? 'O' : (board[r][c] == 'O') ? 'X' : board[r][c];
}

int main(){
//     vector<vector<char>> board = 
//    {{'X','X','X','X'},
//     {'X','O','O','X'},
//     {'X','O','O','X'},
//     {'X','X','X','O'}};
vector<vector<char>> board = 
   {{'O','X','X','O','X'},
    {'X','O','O','X','O'},
    {'X','O','X','O','X'},
    {'O','X','O','O','O'},
    {'X','X','O','X','O'}};
    for(int r= 0; r<board.size();++r){
        for(int c=0; c<board[r].size();++c){
            cout << board[r][c];
        }cout << endl;
    }

    solve(board);
    cout << endl;
    for(int r= 0; r<board.size();++r){
        for(int c=0; c<board[r].size();++c){
            cout << board[r][c];
        }cout << endl;
    }

    return 0;
}