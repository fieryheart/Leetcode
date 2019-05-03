class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        vector<int> minPrices(prices.size(), 0);
        for(int i = 0; i < prices.size(); ++i) {
            if(i == 0) minPrices[i] = prices[i];
            else minPrices[i] = prices[i] < minPrices[i-1] ? prices[i] : minPrices[i-1];
        }
        for(int i = 0; i < prices.size(); ++i) {
            if(prices[i] - minPrices[i] >= 0)
                profit = max(profit, prices[i] - minPrices[i]);
        }
        return profit;
    }
};