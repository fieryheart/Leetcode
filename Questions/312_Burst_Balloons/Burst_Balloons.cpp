class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        
        for(int len = 1; len <= n; ++len) {
            for(int start = 1; start <= n-len+1; ++start) {
                int endd = start+len-1;
                int bestCoin = 0;
                for(int pop = start; pop <= endd; ++pop) {
                    int coin = dp[start][pop-1] + dp[pop+1][endd] + nums[start-1]*nums[pop]*nums[endd+1];
                    bestCoin = max(bestCoin, coin);
                }
                dp[start][endd] = bestCoin;
            }
        }
        return dp[1][n];
    }
};