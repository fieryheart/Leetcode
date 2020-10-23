class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        vector<int> ans;
        while (true) {
            for (int i = left; i <= right; ++i) ans.push_back(matrix[top][i]);
            if (++top > bottom) break;
            for (int i = top; i <= bottom; ++i) ans.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int i = right; i >= left; --i) ans.push_back(matrix[bottom][i]);
            if (--bottom < top) break;
            for (int i = bottom; i >= top; --i) ans.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return ans;
    }
};