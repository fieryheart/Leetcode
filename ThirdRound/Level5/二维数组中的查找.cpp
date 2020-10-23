

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size(), n = matrix[0].size();
        int x = m-1, y = 0;
        while (x >= 0 && y <= n-1) {
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] < target) ++y;
            else if (matrix[x][y] > target) --x;
        }
        return false;
    }
};