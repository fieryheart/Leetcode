#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        vector<bool> jump(nums.size(), false);
        jump[0] = true;
        for(int i = 0; i < nums.size();++i) {
            if(jump[i] == false || i+nums[i] <= max_jump) continue;
            for(int j = 1; i+j < nums.size() && j <= nums[i]; ++j) {
                jump[i+j] = true;
            }
            max_jump = max(max_jump, i+nums[i]);
        }
        return jump[nums.size()-1];
    }
};
int main()
{
    vector<int> nums = {3,2,1,0,4};
    Solution s;
    bool rst = s.canJump(nums);
    cout << rst << endl;
    return 0;
}