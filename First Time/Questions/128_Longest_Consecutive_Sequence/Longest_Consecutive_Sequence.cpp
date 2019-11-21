#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        map<int, bool> mapp;
        int ans = 1, temp = 0, last = nums[0];
        for(int i = 0; i < nums.size(); ++i) {
            mapp[nums[i]] = true;
            last = min(last, nums[i]);
        }
        for(auto it = mapp.begin(); it != mapp.end(); ++it) {
            if(it->first == last) continue;
            else if(it->first - last == 1) temp++;
            else {
                ans = max(ans, temp+1);
                temp = 0;
            }
            last = it->first;
        }
        ans = max(ans, temp+1);
        return ans;
    }
};
int main()
{
    vector<int> nums = {0,-1};
    Solution s;
    int rst = s.longestConsecutive(nums);
    cout << rst << endl;
    return 0;
}