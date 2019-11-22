/*
 * @Author: fieryheart 
 * @Date: 2019-11-22 19:33:02 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-11-22 20:27:30
 */

#include "../../lib/Root.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> vec1 = nums1;
        vector<int> vec2 = nums2;
        if(len1 > len2) {
            vec1 = nums2;
            vec2 = nums1;
        }
        len1 = vec1.size();
        len2 = vec2.size();
        int vec1_left =  0, vec1_right = len1;
        while(true) {
            int i = (vec1_left + vec1_right) / 2, j = (len1 + len2 + 1) / 2 - i;
            if(i > 0 && vec1[i-1] > vec2[j]) {
                vec1_right = i-1;
            } else if(i < len1 && vec2[j-1] > vec1[i]) {
                vec1_left = i+1;
            } else {
                int max_of_left, min_of_right;
                if(i == 0) max_of_left = vec2[j-1];
                else if(j == 0) max_of_left = vec1[i-1];
                else max_of_left = max(vec1[i-1], vec2[j-1]);

                if((len1+len2)&1) return max_of_left / 1.0;

                if(i == len1) min_of_right = vec2[j];
                else if(j == len2) min_of_right = vec1[i];
                else min_of_right = min(vec1[i], vec2[j]);

                return (max_of_left + min_of_right) / 2.0;
            }
        }
    }
};

int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    Solution solu;
    double ans = solu.findMedianSortedArrays(nums1, nums2);
    Print::print(ans);
    return 0;
}