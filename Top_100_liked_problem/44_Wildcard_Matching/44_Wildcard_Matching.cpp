#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.length();
        int pl = p.length();
        vector<vector<bool>> dp(sl+1, vector<bool>(pl+1, false));
        dp[0][0] = true;
        for(int i = 0; i < sl; ++i) dp[i+1][0] = false;
        for(int i = 0; i < pl; ++i) dp[0][i+1] = dp[0][i] ? (p[i] == '*' ? true : false) : false;
        for(int i = 0; i < s.length(); ++i) {
            for(int j = 0; j < p.length(); ++j) {
                if(p[j] == '?') dp[i+1][j+1] = dp[i][j];
                else if(p[j] == '*') dp[i+1][j+1] = dp[i][j] || dp[i+1][j] || dp[i][j+1];
                else {
                    if(dp[i][j] && s[i] == p[j]) dp[i+1][j+1] = true;
                    else dp[i+1][j+1] = false;
                }
            }
        }
        return dp[sl][pl];
    }
};
int main()
{
    string s = "ho";
    string p = "**ho";
    Solution solu;
    bool ans = solu.isMatch(s, p);
    return 0;
}