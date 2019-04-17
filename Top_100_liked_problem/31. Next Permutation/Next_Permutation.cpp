#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int this_per = -1, next_per = -1;
        for(int i = 0; i < nums.size(); ++i) {
            if(i+1 < nums.size() && nums[i] < nums[i+1]) {
                this_per = i;
                next_per = i+1;
            }
            if(this_per != -1 && i > next_per && nums[this_per] < nums[i] && nums[next_per] > nums[i]) next_per = i;
        }
        if(this_per != -1) {
            swap(nums[this_per], nums[next_per]);
            sort(nums.begin()+this_per+1, nums.end());
        }  
        else sort(nums.begin(), nums.end());
    }
};
int main()
{
    vector<int> nums = {1, 3, 2};
    Solution s;
    s.nextPermutation(nums);
    for(int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i];
    }
    cout << endl;
    return 0;
}