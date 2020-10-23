class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int left = 1, right = 2;
        while (left < right) {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum > target) {
                left++;
            } else if (sum < target) {
                right++;
            } else {
                vector<int> arr;
                for (int i = left; i <= right; ++i) {
                    arr.push_back(i);
                }
                ans.push_back(arr);
                left++;
            }
        }
        return ans;
    }
};