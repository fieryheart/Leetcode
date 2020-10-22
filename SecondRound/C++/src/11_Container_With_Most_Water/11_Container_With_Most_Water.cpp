/*
 * @Author: fieryheart 
 * @Date: 2019-12-10 20:37:06 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-10 20:56:31
 * @Desc: The key of this problem is to search from both sides and get the smaller number between the left number and the right number.
 * When find the smaller number is left, it's important to search from the left and find one which larger than it. When it's the right, the same way is done.
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, max_area = 0;
        while(left < right) {
            int temp = min(height[left], height[right]);
            max_area = max(max_area, temp*(right-left));
            if(height[left] > temp) {
                while(left < right && height[right] <= temp) right--;
            } else {
                while(left < right && height[left] <= temp) left++;
            }
        }
        return max_area;
    }
};

//==============================================================

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solu;
    int ans = solu.maxArea(height);
    Print::print(ans);
    return 0;
}