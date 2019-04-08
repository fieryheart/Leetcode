#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // if(nums1.size() == 0) {
        //     int len2 = nums2.size();
        //     return (nums2[(len2-1)/2] + nums2[len2/2]) / 2.0;
        // }
        // if(nums2.size() == 0) {
        //     int len1 = nums1.size();
        //     return (nums1[(len1-1)/2] + nums1[len1/2]) / 2.0;
        // }
        
        for(int i = 0; i < nums2.size(); ++i)
            nums1.push_back(nums2[i]);
        sort(nums1.begin(), nums1.end());
        int len = nums1.size();
        return (nums1[(len-1)/2] + nums1[len/2]) / 2.0;
    }
};


int main()
{
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    Solution s;
    double rst = s.findMedianSortedArrays(nums1, nums2);
    cout << rst << endl;
    return 0;
}