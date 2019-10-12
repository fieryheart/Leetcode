class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int idx = 0;
        while(idx < nums.size()) {
            if(nums[idx]-1 == idx || nums[idx] == nums[nums[idx]-1]) idx++;
            else swap(nums[idx], nums[nums[idx]-1]);
        }
        for(idx = 0; idx < nums.size(); ++idx) {
            if(nums[idx]-1 != idx) ans.push_back(idx+1);
        }
        return ans;
    }
};