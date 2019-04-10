#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(vector<int> q, vector<int> p)
{
    return q[0] != p[0] ? q[0] < p[0] : (q[1] != p[1] ? q[1] < p[1] : q[2] < p[2]);
}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rst, ans;
        map<int, vector<int>> mapp;
        for(int i = 0; i < nums.size(); ++i) {
            mapp[nums[i]].push_back(i);
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i+1; j < nums.size(); ++j)
            {
                int oppo = -(nums[i]+nums[j]);
                for(int k = 0; k < mapp[oppo].size(); ++k)
                {
                    if(mapp[oppo][k] > j) {
                        vector<int> v = {nums[i], nums[j], oppo};
                        sort(v.begin(), v.end());
                        rst.push_back(v);
                    }
                }
            }
        }
        sort(rst.begin(), rst.end(), cmp);
        for(int i = 0; i < rst.size(); ++i)
        {
            if(i && rst[i][0] == rst[i-1][0] && rst[i][1] == rst[i-1][1] && rst[i][2] == rst[i-1][2]) continue;
            ans.push_back(rst[i]);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> rst = s.threeSum(nums);
    for(int i = 0; i < rst.size(); ++i) {
        for(int j = 0; j < rst[i].size(); ++j) {
            cout << rst[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}