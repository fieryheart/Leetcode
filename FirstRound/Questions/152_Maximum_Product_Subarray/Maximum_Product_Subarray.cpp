#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> temp;
        bool flag = false;
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != 1)
                temp.push_back(nums[i]);
            else flag = true;
        nums = temp;
        temp.clear();
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] == -1 && i+1 < nums.size() && nums[i+1] == -1) {
                ++i;
                flag = true;
            }
            else temp.push_back(nums[i]);
        if(flag) temp.push_back(1);
        nums = temp;

        // for(int i = 0; i < nums.size(); ++i){
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        int n = nums.size(), ans = nums[0];
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
            ans = max(ans, dp[i][i]);
            for(int j = i+1; j < n; ++j) {
                dp[i][j] = dp[i][j-1] * nums[j];
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {-4,-3};
    Solution s;
    int rst = s.maxProduct(nums);
    cout << rst << endl;
    return 0;
}