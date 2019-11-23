/*
 * @Author: fieryheart 
 * @Date: 2019-11-21 14:30:48 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-11-23 15:15:11
 * @Desc: Use the hash table to maintain the indices, and then traverse the numbers.
 * If the difference between target and current number can be found in the hash table, we will get the answer.
 * Note that searching in the hash table is before putting the index of current number into hash table.
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mapp;
        for(int i = 0; i < nums.size(); ++i) {
            if(mapp.find(target - nums[i]) != mapp.end() && mapp[target - nums[i]] != i) {
                return {mapp[target - nums[i]], i};
            }
            mapp[nums[i]] = i;
        }
        return {0, 0};
    }
};

//==============================================================

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solu;
    vector<int> ans = solu.twoSum(nums, target);
    Print::print(ans);
    return 0;
}