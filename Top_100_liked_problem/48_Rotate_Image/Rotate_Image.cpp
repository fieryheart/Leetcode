#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; ++i) {
            for(int j = i; j < n-i-1; ++j) swap(matrix[i][j], matrix[j][n-i-1]);
            for(int j = i; j < n-i-1; ++j) swap(matrix[i][j], matrix[n-i-1][n-j-1]);
            for(int j = i; j < n-i-1; ++j) swap(matrix[i][j], matrix[n-j-1][i]);
        }
    }
};
int main()
{
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution s;
    s.rotate(matrix);
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}