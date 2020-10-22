/*
 * @Author: fieryheart 
 * @Date: 2019-12-12 19:31:39 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-12 20:07:50
 * @Desc: To solve this, we can put these strings side by side, then compare whether the characters in the same column are equal to each other.
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i = 0;
        if(strs.empty() || strs[0].empty()) return ans;
        while(true) {
            if(i >= strs[0].length()) return ans;
            char temp = strs[0][i];
            for(int k = 1; k < strs.size(); ++k) {
                if(i >= strs[k].length() || strs[k][i] != temp) return ans;
            }
            ans += temp;
            i++;
        }
        return ans;
    }
};

//==============================================================

int main()
{
    vector<string> strs = {"dog","racecar","car"};
    Solution solu;
    string ans = solu.longestCommonPrefix(strs);
    Print::print(ans);
    return 0;
}