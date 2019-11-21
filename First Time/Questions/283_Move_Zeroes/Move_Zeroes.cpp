class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, k = 0;
        for(; i < nums.size(); ++i) {
            if(nums[i]) nums[k++] = nums[i];
        }
        for(; k < nums.size(); ++k)
            nums[k] = 0;
    }
};