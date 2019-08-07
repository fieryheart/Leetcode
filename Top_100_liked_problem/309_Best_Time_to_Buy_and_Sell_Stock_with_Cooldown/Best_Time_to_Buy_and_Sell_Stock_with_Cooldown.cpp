class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // int dp[n+2][2] = {0};
        // dp[0][0] = dp[1][0] = 0;
        // dp[0][1] = dp[1][1] = INT_MIN;
        // for(int i = 0; i < n; ++i) {
        //     dp[i+2][0] = max(dp[i+1][0], dp[i+1][1] + prices[i]);
        //     dp[i+2][1] = max(dp[i+1][1], dp[i][0] - prices[i]);
        // }
        // return dp[n+1][0];
        
        int pre_hold, hold, pre_not_hold, not_hold;
        pre_hold = hold = INT_MIN;
        pre_not_hold = not_hold = 0;
        for(int i = 0; i < prices.size(); ++i) {
            pre_hold = hold;
            hold = max(hold, pre_not_hold - prices[i]);
            pre_not_hold = not_hold;
            not_hold = max(not_hold, pre_hold + prices[i]);
        }
        return not_hold;
    }
};