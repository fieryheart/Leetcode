#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> path(m, vector<int>(n,0));
        path[0][0] = grid[0][0];
        for(int i = 1; i < n; ++i) path[0][i] = path[0][i-1] + grid[0][i];
        for(int i = 1; i < m; ++i) path[i][0] = path[i-1][0] + grid[i][0];
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                path[i][j] = min(path[i-1][j], path[i][j-1]) + grid[i][j];
            }
        }
        return path[m-1][n-1];
    }
};
int main()
{
    vector<vector<int>> grid = {{1,3,1},
                                {1,5,1},
                                {4,2,1}};
    Solution s;
    int rst = s.minPathSum(grid);
    cout << rst << endl;
    return 0;
}