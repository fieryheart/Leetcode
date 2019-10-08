#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> subs(9, vector<bool>(9, false));
        for(int i = 0;i < 9; i++) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;
                int t = board[i][j] - '1';
                if(rows[i][t] 
                || cols[j][t] 
                || subs[i/3*3+j/3][t]) return false;
                rows[i][t] = true;
                cols[j][t] = true;
                subs[i/3*3+j/3][t] = true;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> board = {
                                    {'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'},
                                };

    Solution s;
    bool ans = s.isValidSudoku(board);
    cout << ans << endl;
    return 0;
}