// 关键在于 找出target 和 target-1 的右边界，使得代码能够复用
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchRight(nums, target) - searchRight(nums, target-1);
    }
    int searchRight(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] <= target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return left;
    }
};