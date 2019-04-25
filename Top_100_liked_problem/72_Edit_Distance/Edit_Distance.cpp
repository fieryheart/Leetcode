#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i = 1;i <= m; ++i) dp[i][0] = i;
        for(int i = 1;i <= n; ++i) dp[0][i] = i;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(word2[j-1] == word1[i-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
        return dp[m][n];
    }
};
int main()
{
    string word1 = "", word2 = "a";
    Solution s;
    int rst = s.minDistance(word1, word2);
    cout << rst << endl;
    return 0;
}