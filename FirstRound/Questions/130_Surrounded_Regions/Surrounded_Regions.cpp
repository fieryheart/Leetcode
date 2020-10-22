#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> flip(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            if(board[i][0] == 'O' && !flip[i][0]) {
                search(i, 0, m, n, flip, board);
            }
            if(board[i][n-1] == 'O' && !flip[i][n-1]) {
                search(i, n-1, m, n, flip, board);
            }
        }
        for(int i = 0;i < n; ++i) {
            if(board[0][i] == 'O' && !flip[0][i]) {
                search(0, i, m, n, flip, board);
            }
            if(board[m-1][i] == 'O' && !flip[m-1][i]) {
                search(m-1, i, m, n, flip, board);
            }
        }
        for(int i = 1; i < m-1; ++i) {
            for(int j = 1; j < n-1; ++j) {
                if(board[i][j] == 'O' && !flip[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void search(int r, int c, int m, int n, vector<vector<bool>> &flip, vector<vector<char>>& board) {
        if(board[r][c] == 'X') return;
        else flip[r][c] = true;
        if(r-1 >= 0 && !flip[r-1][c]) search(r-1, c, m, n, flip, board);
        if(r+1 < m && !flip[r+1][c])  search(r+1, c, m, n, flip, board);
        if(c-1 >= 0 && !flip[r][c-1]) search(r, c-1, m, n, flip, board);
        if(c+1 < n && !flip[r][c+1])  search(r, c+1, m, n, flip, board);
    }
};

int main()
{
    vector<vector<char>> board = {
                                    {'X', 'X', 'X', 'X'}, 
                                    {'X', 'O', 'O', 'X'}, 
                                    {'X', 'X', 'O', 'X'}, 
                                    {'X', 'O', 'X', 'X'}
                                };
    Solution s;
    s.solve(board);
    for(int i = 0;i < board.size(); ++i) {
        for(int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}