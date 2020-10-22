#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<int>& temp, int start, int n) {
        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        } else {
            for(int i = start+1; i < nums.size(); ++i) {
                temp.push_back(nums[i]);
                dfs(ans, nums, temp, i, n);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i = 1; i <= nums.size(); ++i) {
            vector<int> temp;
            for(int j = 0; j + i - 1 < nums.size(); ++j) {
                temp.push_back(nums[j]);
                dfs(ans, nums, temp, j, i);
                temp.pop_back();
            }
                
        }
        return ans;    
    }
};
int main()
{
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int>> rst = s.subsets(nums);
    for(int i = 0; i < rst.size(); ++i) {
        for(int j = 0; j < rst[i].size(); ++j) {
            cout << rst[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}