class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int tmp = nums[0], i = 1;
        while(i < nums.size()) {
            if(nums[i] == tmp) nums.erase(nums.begin()+i);
            else tmp = nums[i++];
        }
        return nums.size();
    }
};