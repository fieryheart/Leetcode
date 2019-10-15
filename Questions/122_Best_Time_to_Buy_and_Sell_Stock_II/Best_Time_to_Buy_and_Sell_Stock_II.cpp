class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<int> trend(prices.size()-1, 0);
        for(int i = 0; i < trend.size(); ++i) {
            if(prices[i+1]-prices[i] >= 0) trend[i] = 1;
            else trend[i] = -1;
        }
        trend.push_back(-1);
        int buy = -1, sell = 0;
        for(int i = 0; i < trend.size(); ++i) {
            if(buy == -1 && trend[i] == 1) {
                buy = prices[i];
            } else if(buy != -1 && trend[i] == -1) {
                sell += (prices[i] - buy);
                buy = -1;
            }
        }
        return sell;
    }
};