#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        bitset<100*200/2 +1> dp;
        dp[0] = 1;
        for (auto n : nums) {
            sum += n;
            dp |= dp << n;
        }
        return !(sum%2) && dp[sum/2];
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    Solution s;
    bool ans = s.canPartition(nums);
    return 0;
}