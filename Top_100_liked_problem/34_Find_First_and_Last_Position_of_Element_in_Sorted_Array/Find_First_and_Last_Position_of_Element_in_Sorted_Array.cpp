#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        vector<int> ans = {-1,-1};
        while(left <= right) {
            int mid = (left+right) / 2;
            if(nums[mid] == target) {
                int target_left = left, target_right = mid, target_mid;
                while(target_left <= target_right) {
                    target_mid = (target_left + target_right) / 2;
                    if(nums[target_mid] == target && (target_mid == 0 || nums[target_mid] > nums[target_mid-1])) {
                        ans[0] = target_mid;
                        break;
                    } else if(nums[target_mid] < target) target_left = target_mid+1;
                    else target_right = target_mid-1;
                }
                target_left = mid, target_right = right;
                while(target_left <= target_right) {
                    target_mid = (target_left + target_right) / 2;
                    if(nums[target_mid] == target && (target_mid == nums.size()-1 || nums[target_mid] < nums[target_mid+1])) {
                        ans[1] = target_mid;
                        break;
                    } else if(nums[target_mid] > target) target_right = target_mid-1;
                    else target_left = target_mid+1;
                }
                break;
            } else if(nums[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 6;
    Solution s;
    vector<int> rst = s.searchRange(nums, target);
    cout << rst[0] << " " << rst[1] << endl;
    return 0;
}