class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0, m = costs.size();
        for(int i = 0; i < m; ++i) ans += costs[i][0];
        vector<int> ds(m, 0);
        for(int i = 0; i < m; ++i) ds[i] = costs[i][1] - costs[i][0];
        sort(ds.begin(), ds.end());
        for(int i = 0; i < m/2; ++i) ans += ds[i];
        return ans;
    }
};