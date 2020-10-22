class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return 0;
        int arr[n][2] = {0};
        arr[0][0] = nums[0];
        arr[n-1][1] = nums[n-1];
        for(int i = 1; i < n; ++i) arr[i][0] = max(arr[i-1][0], nums[i]);
        for(int i = n-2; i >= 0; --i) arr[i][1] = min(arr[i+1][1], nums[i]);
        
        int left = 0, right = n-1;
        while(left < n-1 && nums[left] <= nums[left+1]) left++;
        if(left == n-1) return 0;
        while(right > 0 && nums[right] >= nums[right-1]) right--;
        if(right == 0) return 0;
        
        if(right <= left) return 0;
        
        int minn = INT_MAX, maxn = INT_MIN;
        for(int i = left; i <= right; ++i) {
            minn = min(minn, nums[i]);
            maxn = max(maxn, nums[i]);
        }
        
        int back = left-1;
        while(back >= 0 && arr[back][0] > minn) back--;
        left = back;
        back = right+1;
        while(back < n && arr[back][1] < maxn) back++;
        right = back;
        
        return right - left - 1;
    }
};