#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& ans, int &m, int &n, vector<vector<bool>>& visit, int &square, int r, int c, int color) {
        visit[r][c] = true;
        // cout << r << " " << c << endl;
        if(r == 0 || r == m-1 || c == 0 || c == n-1 || grid[r-1][c] != square || grid[r+1][c] != square || grid[r][c-1] != square || grid[r][c+1] != square)
            ans[r][c] = color;
        if(r-1 >= 0 && !visit[r-1][c] && grid[r-1][c] == square) dfs(grid, ans, m, n, visit, square, r-1, c, color);
        if(r+1 < m && !visit[r+1][c] && grid[r+1][c] == square) dfs(grid, ans, m, n, visit, square, r+1, c, color);
        if(c-1 >= 0 && !visit[r][c-1] && grid[r][c-1] == square) dfs(grid, ans, m, n, visit, square, r, c-1, color);
        if(c+1 < n && !visit[r][c+1] && grid[r][c+1] == square) dfs(grid, ans, m, n, visit, square, r, c+1, color);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int m = grid.size(), n = grid[0].size(), square = grid[r0][c0];
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        vector<vector<int>> ans = grid;
        dfs(grid, ans, m, n, visit, square, r0, c0, color);
        return ans;
    }
};
int main()
{
    vector<vector<int>> grid = {{1,2,1,2,1,2},{2,2,2,2,1,2},{1,2,2,2,1,2}};
    int r0 = 1, c0 = 3, color = 1;
    Solution s;
    vector<vector<int>> rst = s.colorBorder(grid, r0, c0, color);
    for(int i = 0; i < rst.size(); ++i) {
        for(int j = 0; j < rst[i].size(); ++j) {
            cout << rst[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}