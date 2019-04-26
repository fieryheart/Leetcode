#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color[3] = {0},idx = 0;
        for(int i = 0; i < nums.size(); ++i)
            color[nums[i]]++;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < color[i]; j++)
                nums[idx++] = i;
    }
};
int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(nums);
    for(int i = 0; i < nums.size(); ++i)
        cout << nums[i] << " ";
    return 0;
}