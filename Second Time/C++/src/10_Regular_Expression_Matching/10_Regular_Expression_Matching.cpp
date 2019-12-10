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
        // s is the input
        // p is the pattern

        int sl = s.length()+1;
        int pl = p.length()+1;
        vector<vector<bool>> dp(sl, vector<bool>(pl, false));

        // if bath s and p is empty, the result is true
        dp[0][0] = true;

        // if p is empty, all matching results will be false
        for(int i = 1; i < sl; ++i) dp[i][0] = false;

        // if s is empty
        for(int j = 1; j < pl; ++j) {
            // Because '*' can match zero of the preceding element, we need to know whether dp[0][j-2] is true to determine dp[0][j].  
            if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
            else dp[0][j] = false;
        }
        for(int i = 1; i < sl; ++i) {
            for(int j = 1; j < pl; ++j) {
                // '.' match any single character, so dp[i][j] is determined by dp[i-1][j-1]
                if(p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                
                // '*' match zero or more of the preceding element
                else if(p[j-1] == '*') {

                    // if the preceding element is '.', the matching will be true so long as there is one true matching in dp[k][j-2] 
                    // k is equal or less than i
                    if(p[j-2] == '.') {
                        dp[i][j] = false;
                        for(int k = 0; k <= i && !dp[i][j]; ++k) {
                            dp[i][j] = dp[k][j-2];
                        }
                    }

                    // if the preceding element is equal to s[i-1]
                    // we need to match respectively s[:i] and p[:j-2], s[:i-1] and p[:j]
                    else if(p[j-2] == s[i-1]) dp[i][j] = dp[i-1][j] || dp[i][j-2];
                    else dp[i][j] = dp[i][j-2];
                } 
                
                // check whether s[i-1] is equal to p[j-1]
                else {
                    if(p[j-1] == s[i-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    } else dp[i][j] = false;
                }
            }
        }
        // Print::print(dp);
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