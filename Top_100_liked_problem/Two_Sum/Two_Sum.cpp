#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> rst;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    rst.push_back(i);
                    rst.push_back(j);
                    break;
                }
            }
        }
        return rst;
    }
    // hash解法
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> rst;
        map<int, int> mapi;
        map<int, bool> mapb;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(mapb[target-nums[i]]) {
                rst.push_back(mapi[target-nums[i]]);
                rst.push_back(i);
                break;
            }
            mapb[nums[i]] = true;
            mapi[nums[i]] = i;
        }
        return rst;
    }    
};
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<int> rst = s.twoSum2(nums, target);
    if(rst.size()) {
        cout << "[" << rst[0] << ", " << rst[1] << "]" << endl;
    } else {
        cout << "[]" << endl;
    }
    return 0;
}