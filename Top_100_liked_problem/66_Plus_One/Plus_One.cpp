class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.size()+1, 0);
        int carry = 1;
        for(int i = digits.size(); i > 0; --i) {
            ans[i] = (digits[i-1] + carry) % 10;
            carry = (digits[i-1] + carry) / 10;
        }
        if(carry) ans[0] = 1;
        else ans.erase(ans.begin());
        return ans;
    }
};