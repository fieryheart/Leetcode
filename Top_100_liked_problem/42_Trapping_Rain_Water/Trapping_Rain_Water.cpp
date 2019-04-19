#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        vector<int> new_height;
        new_height.push_back(-1);
        for(int i = 0; i < height.size(); ++i) {
            new_height.push_back(height[i]);
        }
        vector<int> left_height(new_height.size(), 0);
        vector<int> right_height(new_height.size(), 0);
        left_height[0] = right_height[new_height.size()-1] = -1;
        for(int i = 1; i < left_height.size()-1; ++i) {
            left_height[i] = max(left_height[i-1], new_height[i-1]);
        }
        for(int i = right_height.size()-2; i > 0; --i) {
            right_height[i] = max(right_height[i+1], new_height[i+1]);
        }
        for(int i = 1; i < new_height.size()-1; ++i) {
            if(left_height[i] > new_height[i] && right_height[i] > new_height[i]) {
                sum += min(left_height[i]-new_height[i], right_height[i]-new_height[i]);
                // cout << i << " " << min(left_height[i]-new_height[i], right_height[i]-new_height[i]) << endl;
            }
        }
        return sum;
    }
};
int main()
{
    vector<int> height = {1};
    Solution s;
    int rst = s.trap(height);
    cout << rst << endl;
    return 0;
}