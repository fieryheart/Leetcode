class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length() == 0) return true;
        vector<bool> dp(s.length()+1, false);
        map<string, bool> mapp;
        for(int i = 0; i < wordDict.size(); ++i)
            mapp[wordDict[i]] = true;
        dp[0] = true;
        for(int i = 1; i <= s.length(); ++i) {
            for(int j = i-1; j >= 0; --j) {
                if(dp[j]) {
                    string str = s.substr(j, i-j);
                    if(mapp[str]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};