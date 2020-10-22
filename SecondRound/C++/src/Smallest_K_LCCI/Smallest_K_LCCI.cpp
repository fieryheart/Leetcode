/*
 * @Author: your name
 * @Date: 2020-09-04 10:39:38
 * @LastEditTime: 2020-09-04 10:50:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /Leetcode/Second Time/C++/src/Smallest_K_LCCI/Smallest_K_LCCI.cpp
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int N = arr.size();
        if (k == 0) return {};
        int left = 0, right = N-1;
        while (true) {
            int mid = partion(arr, left, right);
            if (mid == k-1) {
                break;
            } else if (mid < k-1) {
                left = mid+1;
            } else if (mid > k-1) {
                right = mid-1;
            }
            Print::print(to_string(left) + " " + to_string(right));
        }
        arr.resize(k);
        return arr;
    }
    int partion(vector<int>&arr, int left, int right) {
        int pivot = arr[left];
        while (left < right) {
            while (left < right && arr[right] > pivot) right--;
            arr[left] = arr[right];
            while (left < right && arr[left] <= pivot) left++;
            arr[right] = arr[left];
        }
        arr[left] = pivot;
        return left;
    }
};

//==============================================================

int main()
{
    vector<int> nums = {1,3,5,7,2,4,6,8};
    int k = 4;
    Solution solu;
    vector<int> ans = solu.smallestK(nums, k);
    Print::print(ans);
    return 0;
}