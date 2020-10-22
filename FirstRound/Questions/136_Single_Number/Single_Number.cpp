#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size(); ++i)
            ans ^= nums[i];
        return ans;
    }
};
int main()
{
    vector<int> nums = {2,2,1};
    Solution s;
    int rst = s.singleNumber(nums);
    cout << rst << endl;
    return 0;
}