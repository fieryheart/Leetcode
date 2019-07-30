class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; ++i) {
            ans[i] = 1;
            for(int j = i-1; j >= 0; --j) {
                if(nums[i] > nums[j])
                    ans[i] = max(ans[i], ans[j]+1);
            }
        }
        int maxn = 0;
        for(int i = 0; i < n; ++i) 
            maxn = max(ans[i], maxn);
        return maxn;
    }
};