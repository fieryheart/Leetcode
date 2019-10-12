class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size1 = nums1.size(), size2 = nums2.size();
        int size = m+n-1;
        int k1 = m-1, k2 = n-1;
        while(k1 >= 0 && k2 >= 0) {
            if(nums1[k1] > nums2[k2]) {
                nums1[size--] = nums1[k1--];
            } else {
                nums1[size--] = nums2[k2--];
            }
        }
        while(k2 >= 0) {
            nums1[size--] = nums2[k2--];
        }
    }
};