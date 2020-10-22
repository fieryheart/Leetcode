class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S) return 0;
        sum += S;
        if(sum & 1) return 0;
        sum >>= 1;
        int dp[sum+1] = {0};
        dp[0] = 1;
        for(auto n : nums) {
            for(int i = sum; i >= n; --i) {
                dp[i] += dp[i-n];
            }
        }
        return dp[sum];
    }
};