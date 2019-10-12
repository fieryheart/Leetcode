class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        
        for(int i = 0; i < rows; ++i) {
            if(matrix[i][0] == 0) col0 = 0;
            for(int j = 1; j < cols; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < cols; ++i) {
            if(matrix[0][i] == 0) {
                for(int j = 1; j < rows; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        for(int i = 0; i < rows; ++i) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < cols; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(col0 == 0) {
            for(int i = 0; i < rows; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};