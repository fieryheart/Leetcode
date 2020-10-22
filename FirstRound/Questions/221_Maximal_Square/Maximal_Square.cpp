#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> row(m, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == '0') row[j] = 0;
                else row[j]++;
            }
            
            // for(int j = 0; j < m; ++j) {
            //     cout << row[j] << " ";
            // }
            // cout << endl;

            int side = 0, minHeight = 0;
            for(int j = 0; j < m; ++j) {
                side = row[j];
                minHeight = row[j];
                for(int w = 0; w < row[j]; ++w) {
                    // if(j+w<m) side = min(w+1, row[j+w]);
                    // else {
                    //     side = min(side, m-j);
                    //     break;
                    // }
                    if(j+w >= m) break;
                    minHeight = min(minHeight, row[j+w]);
                    if(w+1 > minHeight) break;
                    side = min(w+1, minHeight);
                    maxArea = max(maxArea, side*side);
                }
                // cout << "side: " << side << endl;
                // maxArea = max(maxArea, side*side);
            }
            // cout << "maxArea: " << maxArea << endl;
        }
        return maxArea;
    }
};

int main()
{
    // vector<vector<char>> matrix = { {'1','0','1','0','0'},
    //                                 {'1','0','1','1','1'},
    //                                 {'1','1','1','1','1'},
    //                                 {'1','0','0','1','0'} };

    vector<vector<char>> matrix = { {'0','1','1','0','1'},
                                    {'1','1','0','1','0'},
                                    {'0','1','1','1','0'},
                                    {'1','1','1','1','0'}, 
                                    {'1','1','1','1','1'},
                                    {'0','0','0','0','0'} };

    Solution s;
    int rst = s.maximalSquare(matrix);
    cout << rst << endl;
    return 0;
}