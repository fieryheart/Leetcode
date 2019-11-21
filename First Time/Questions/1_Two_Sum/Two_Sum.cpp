#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Q: 

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

*/


/*
Desc:

    The basic idea is to maintain a hash table for each element in nums, 
    using num as key and its index (0-based) as value. 
    For each num, search for target - num in the hash table. 
    If it is found and is not the same element as num, then we are done.

    The code is as follows. 
    Note that each time before we add num to map, 
    we search for target - num first and so we will not hit the same element.
*/

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