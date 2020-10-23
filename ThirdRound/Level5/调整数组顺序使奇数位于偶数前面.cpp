/*
    使用快慢指针来定位奇偶数，慢指针指向之前的偶数位置，
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int numn = nums.size();
        int slow = 0, fast = 0;
        while (fast < numn && slow < numn) {
            if (nums[fast] % 2) {
                if (slow < fast) {
                    swap(nums[slow], nums[fast]);
                    ++slow;
                    while (slow < fast && nums[slow] % 2) ++slow;
                    ++fast;
                } else {
                    ++fast;
                    ++slow;
                }

            } else {
                ++fast;
            }
        }
        return nums;
    }
};