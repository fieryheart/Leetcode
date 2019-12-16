class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if not len(nums1): return (nums2[(len(nums2)-1)//2]+nums2[len(nums2)//2]) / 2.0
        if not len(nums2): return (nums1[(len(nums1)-1)//2]+nums1[len(nums1)//2]) / 2.0
        if len(nums1) > len(nums2):
            temp = nums1
            nums1 = nums2
            nums2 = temp
        nums1_left = 0 
        nums1_right = len(nums1)
        while True:
            i = (nums1_left + nums1_right) // 2
            j = (len(nums1)+len(nums2)+1) // 2 - i
            if i > 0 and nums1[i-1] > nums2[j]:
                nums1_right = i-1
            elif i < len(nums1) and nums2[j-1] > nums1[i]:
                nums1_left = i+1
            else:
                max_of_left = min_of_right = 0
                if i == 0: max_of_left = nums2[j-1]
                elif j == 0: max_of_left = nums1[i-1]
                else: max_of_left = max(nums1[i-1], nums2[j-1])
                
                if (len(nums1)+len(nums2))&1: return max_of_left / 1.0
                
                if i == len(nums1): min_of_right = nums2[j]
                elif j == len(nums2): min_of_right = nums1[i]
                else: min_of_right = min(nums1[i], nums2[j])
                    
                return (max_of_left+min_of_right) / 2.0
                
        