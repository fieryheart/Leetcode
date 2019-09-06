class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> prefixSum;
        int cnt = 0;
        prefixSum[0] = 1;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            cnt += prefixSum[sum-k];
            prefixSum[sum]++;
        }
        return cnt;
    }
};