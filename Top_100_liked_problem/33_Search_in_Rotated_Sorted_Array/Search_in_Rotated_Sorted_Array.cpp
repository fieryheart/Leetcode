#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int> &nums, int left, int right, int target) {
        while(left <= right) {
            int mid = (left+right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = (left+right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[left] <= target && target < nums[mid]) return binarySearch(nums, left, mid-1, target);
            else if(nums[mid] < target && target <= nums[right]) return binarySearch(nums, mid+1, right, target);
            else {
                if(nums[mid] >= nums[left]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 3;
    Solution s;
    int rst = s.search(nums, target);
    cout << rst << endl;
    return 0;
}