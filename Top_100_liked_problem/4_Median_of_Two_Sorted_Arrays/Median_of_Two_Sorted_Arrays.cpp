#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 使用sort排序解决问题
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
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
    // O(log(m+n))解法
    // 参考链接：https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn))-solution-with-explanation
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vm, vn;
        if(nums1.size() < nums2.size()) {
            vm = nums1;
            vn = nums2;
        } else {
            vm = nums2;
            vn = nums1;
        }
        int m = vm.size(), n = vn.size();
        int imin = 0, imax = m;
        while(1) {
            int i = (imin + imax) / 2, j = (m + n + 1)/2 - i;
            if(i > 0 && vm[i-1] > vn[j]) {
                imax = i - 1;
            } else if(i < m && vn[j-1] > vm[i]) {
                imin = i + 1;
            } else {
                int max_of_left, min_of_right;
                if(i == 0) max_of_left = vn[j-1];
                else if(j == 0) max_of_left = vm[i-1];
                else max_of_left = max(vm[i-1], vn[j-1]);

                if((m+n)%2) return max_of_left / 1.0;

                if(i == m) min_of_right = vn[j];
                else if(j == n) min_of_right = vm[i];
                else min_of_right = min(vm[i], vn[j]);

                return (max_of_left + min_of_right) / 2.0;
            }
        }
    }
};


int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    Solution s;
    double rst = s.findMedianSortedArrays2(nums1, nums2);
    cout << rst << endl;
    return 0;
}