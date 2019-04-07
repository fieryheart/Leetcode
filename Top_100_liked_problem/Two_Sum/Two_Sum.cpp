#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool flag = false;
        vector<int> rst;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    flag = true;
                    rst.push_back(i);
                    rst.push_back(j);
                    break;
                }
            }
        }
        return rst;
    }
};
int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;
    Solution s;
    vector<int> rst = s.twoSum(nums, target);
    if(rst.size()) {
        cout << "[" << rst[0] << ", " << rst[1] << "]" << endl;
    } else {
        cout << "[]" << endl;
    }
    return 0;
}