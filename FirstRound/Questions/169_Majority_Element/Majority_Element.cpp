class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mapp;
        int n = nums.size(), majority = nums[0];
        for(int i = 0; i < nums.size(); ++i) {
            mapp[nums[i]]++;
            if(mapp[nums[i]] > n / 2) majority = nums[i];
        }
        return majority;
    }
};