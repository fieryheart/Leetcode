/*
 * @Author: fieryheart 
 * @Date: 2019-12-12 19:42:57 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-12 20:20:27
 * @Desc: The key of the solution is to sort firstly, then traverse the numbers. We put every item as the target and find the sum of two numbers
 * which is equal to the target. When we select one target, the only way is to search two suitable numbers from both ends of numbers behind the target. 
 * Note that there are two cases where we should ignore duplicate triplets. One is the repetitive value of target. 
 * The other is the repetitive value of left and right which is considered as the end numbers.
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left < right) {
                int x = nums[left];
                int y = nums[right];
                if(x + y < target) left++;
                else if(x + y > target) right--;
                else {
                    ans.push_back({-target, x, y});
                    while(left < right && nums[left] == x) left++;
                    while(left < right && nums[right] == y) right--;
                }
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};

//==============================================================

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution solu;
    vector<vector<int>> ans = solu.threeSum(nums);
    Print::print(ans);
    return 0;
}