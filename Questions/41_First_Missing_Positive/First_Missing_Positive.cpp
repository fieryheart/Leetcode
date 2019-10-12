#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int idx = 0, n = nums.size();
        nums.push_back(0);
        while(idx <= n) {
            if(nums[idx] <= 0 || nums[idx] > n) nums[idx++] = 0;
            else {
                if(nums[idx] == idx) idx++;
                else {
                    if(nums[nums[idx]] == nums[idx]) nums[idx++] = 0;
                    else swap(nums[nums[idx]], nums[idx]);
                }
            }
        }
        // for(auto n:nums) cout << n << " ";
        // cout << endl;
        for(int i = 1; i <= n; ++i) {
            if(nums[i] == 0) return i;
        }
        return n+1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,0};
    int ans = s.firstMissingPositive(nums);
    cout << ans << endl;
    return 0;
}