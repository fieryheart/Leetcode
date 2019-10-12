#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>> &ans, int start, vector<int> nums) {
        if(start >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            dfs(ans, start+1, nums);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(ans, 0, nums);
        return ans;
    }
};
int main()
{
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int>> rst = s.permute(nums);
    for(int i = 0; i < rst.size();++i) {
        for(int j = 0; j < rst[i].size(); ++j) {
            cout << rst[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}