#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1, h;
        int water = 0;
        while(i < j) {
            h = min(height[i], height[j]);
            water = max(water, (j - i)*h);
            while(height[i] <= h && i < j) i++;
            while(height[j] <= h && i < j) j--;
        }
        return water;
    }
};
int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int rst = s.maxArea(height);
    cout << rst << endl;
    return 0;
}