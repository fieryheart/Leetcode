#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int &m, int &n, vector<vector<bool>> &visit, string &word, int idx, int x, int y) {
        if(idx == word.size()-1 && word[idx] == board[x][y]) return true;
        if(word[idx] != board[x][y]) return false;
        visit[x][y] = true;
        bool flag = false;
        if(x+1 < m && !visit[x+1][y]) flag = flag || dfs(board, m, n, visit, word, idx+1, x+1, y);
        if(x-1 >= 0 && !visit[x-1][y]) flag = flag || dfs(board, m, n, visit, word, idx+1, x-1, y);
        if(y+1 < n && !visit[x][y+1]) flag = flag || dfs(board, m, n, visit, word, idx+1, x, y+1);
        if(y-1 >= 0 && !visit[x][y-1]) flag = flag || dfs(board, m, n, visit, word, idx+1, x, y-1);
        visit[x][y] = false;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        int idx = 0, m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        bool ans = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = ans || dfs(board, m, n, visit, word, 0, i, j);
                if(ans) break;
            }
            if(ans) break;
        }
        return ans;
    }
};
int main()
{
    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','C','S'},
                                  {'A','D','E','E'}};
    string word = "A";
    Solution s;
    bool rst = s.exist(board, word);
    cout << rst << endl;
    return 0;
}