#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea1(vector<int>& heights) {
        int maxArea = 0;
        bool flag = true;
        for(int i = 1; i < heights.size(); ++i) {
            if(heights[i] != heights[i-1])
                flag = false;
            if(!flag) break;
        }
        if(flag && !heights.empty()) return heights[0] * heights.size();
        for(int i = 0; i < heights.size(); ++i) {
            int num = 0, idx = i;
            while(idx < heights.size() && heights[idx++] >= heights[i]) num++;
            idx = i;
            while(idx >= 0 && heights[idx--] >= heights[i]) num++;
            num = num-1;
            maxArea = max(maxArea, num*heights[i]);
        }
        return maxArea;
    }
    int largestRectangleArea2(vector<int> &height) {
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
    vector<int> height = {3,4,5,3};
    Solution s;
    int rst = s.largestRectangleArea2(height);
    cout << rst << endl;
    return 0;
}