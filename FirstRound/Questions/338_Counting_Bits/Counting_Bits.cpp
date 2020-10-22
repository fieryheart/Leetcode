class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        if(num == 0) return ans;
        ans.push_back(1);
        if(num == 1) return ans;
        int p = 1;
        for(int i = 2; i <= num; ++i) {
            if(i % p == 0) {
                ans.push_back(1);
                p = p*2;
            } else {
                ans.push_back(ans[i%p] + ans[p]);
            }
        }
        return ans;
    }
};