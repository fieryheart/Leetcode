#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// 参考：https://leetcode.com/problems/maximal-rectangle/discuss/29059/Sharing-my-straightforward-C%2B%2B-solution-with-O(n2)-time-with-explanation
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()){
            return 0;
        }
        int maxRec = 0;
        vector<int> height(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }
                else{
                    height[j]++;
                }
            }
            maxRec = max(maxRec, largestRectangleArea(height));
        }
        return maxRec;
    }
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        height.push_back(0);
        int maxSize = 0;
        for(int i = 0; i < height.size(); i++){
            if(s.empty() || height[i] >= height[s.top()]){
                s.push(i);
            }
            else{
                int temp = height[s.top()];
                s.pop();
                maxSize = max(maxSize, temp * (s.empty() ? i : i - 1 - s.top()));
                i--;
            }
        }
        return maxSize;
    }
};
int main()
{
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};
    Solution s;
    int rst = s.maximalRectangle(matrix);
    cout << rst << endl;
    return 0;
}