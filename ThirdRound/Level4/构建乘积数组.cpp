// 解法：从左到右扫描，然后从右向左扫描
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> ans(a.size());
        int left = 1;
        for (int i = 0; i < a.size(); ++i) {
            ans[i] = left;
            left *= a[i];
        }
        int right = 1;
        for (int i = a.size()-1; i >= 0; --i) {
            ans[i] *= right;
            right *= a[i];
        }
        return ans;
    }
};