class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        for(int i = T.size()-1; i >= 0; --i) {
            int j = i+1;
            while(j < T.size() && T[j] <= T[i]) {
                if(ans[j]) j += ans[j];
                else j = T.size();
            }
            if(j < T.size()) ans[i] = j - i;
        }
        return ans;
    }
};