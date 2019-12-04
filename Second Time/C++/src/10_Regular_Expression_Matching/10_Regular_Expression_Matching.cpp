/*
 * @Author: fieryheart 
 * @Date: 2019-12-04 18:05:42 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-04 21:22:26
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.length()+1;
        int pl = p.length()+1;
        vector<vector<bool>> dp(sl, vector<bool>(pl, false));
        dp[0][0] = true;
        for(int i = 1; i < sl; ++i) dp[i][0] = false;
        for(int j = 1; j < pl; ++j) {
            dp[0][j] = false;
            if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
        }
        for(int i = 1; i < sl; ++i) {
            for(int j = 1; j < pl; ++j) {
                if(p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') {
                    if(p[j-2] == '.') {
                        for(int k = 0; k <= i; ++k) {
                            if(dp[k][j-2]) {
                                dp[i][j] = true;
                                break;
                            }
                        }
                    } else if(p[j-2] == s[i-1]) dp[i][j] = dp[i-1][j-2] || dp[i][j-2] || dp[i-1][j-1];
                    else dp[i][j] = dp[i][j-2];
                } else {
                    if(p[j-1] == s[i-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    } else dp[i][j] = false;
                }
            }
        }
        Print::print(dp);
        return dp[sl-1][pl-1];
    }
};

//==============================================================

int main()
{
    string s = "aa";
    string p = "a*";
    Solution solu;
    bool ans = solu.isMatch(s, p);
    Print::print(ans);
    return 0;
}