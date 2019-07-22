class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0) return nums;
        vector<int> ans;
        if(k >= nums.size()) {
            int maxn = nums[0];
            for(int i = 0; i < nums.size(); ++i) maxn = max(maxn, nums[i]);
            ans.push_back(maxn);
        } else {
            map<int, int> mapp;
            int maxn = nums[0];
            for(int i = 0; i < k; ++i) {
                maxn = max(maxn, nums[i]);
                mapp[nums[i]]++;
            }
            ans.push_back(maxn);
            for(int i = 1; i+k-1 < nums.size(); ++i) {
                mapp[nums[i-1]]--;
                mapp[nums[i+k-1]]++;
                maxn = max(maxn, nums[i+k-1]);
                if(mapp[maxn] == 0) {
                    maxn = nums[i];
                    for(int j = 0; j < k; ++j) maxn = max(maxn, nums[i+j]);
                }
                ans.push_back(maxn);
            }
        }
        return ans;
    }
};