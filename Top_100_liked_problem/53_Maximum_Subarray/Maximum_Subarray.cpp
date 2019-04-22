#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxn = 0, flag = 0, temp_sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            temp_sum += nums[i];
            if(temp_sum < 0) {
                temp_sum = 0;
            } else if(temp_sum >= maxn) {
                flag = 1;
                maxn = temp_sum;
            }
        }
        if(!flag) {
            maxn = INT_MIN;
            for(int i = 0; i < nums.size(); ++i) {
                if(nums[i] > maxn) {
                    maxn = nums[i];
                }
            }
        }
        return maxn;
    }
};
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    int rst = s.maxSubArray(nums);
    cout << rst << endl;
    return 0;
}