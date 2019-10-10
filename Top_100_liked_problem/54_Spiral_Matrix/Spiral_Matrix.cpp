class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty() || matrix[0].empty()) return ans;
        int col_l = 0, col_r = matrix[0].size()-1;
        int row_t = 0, row_b = matrix.size()-1;
        while(col_l < col_r && row_t < row_b) {
            for(int i = col_l; i <= col_r; ++i) ans.push_back(matrix[row_t][i]);
            for(int i = row_t+1; i <= row_b; ++i) ans.push_back(matrix[i][col_r]);
            for(int i = col_r-1; i >= col_l; --i) ans.push_back(matrix[row_b][i]);
            for(int i = row_b-1; i >= row_t+1; --i) ans.push_back(matrix[i][col_l]);
            col_l++;
            col_r--;
            row_t++;
            row_b--;
        }
        if(col_l == col_r && row_t < row_b) {
            for(int i = row_t; i <= row_b; ++i) ans.push_back(matrix[i][col_l]);
        } else if(col_l < col_r && row_t == row_b) {
            for(int i = col_l; i <= col_r; ++i) ans.push_back(matrix[row_t][i]);
        } else if(col_l == col_r && row_t == row_b) ans.push_back(matrix[row_t][col_l]);
        return ans;
    }
};