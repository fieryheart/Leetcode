/*
 * @Author: fieryheart 
 * @Date: 2019-12-13 09:53:32 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-13 10:14:24
 * @Desc: This question will be easy if you can put the mapping of digit to letters as one matrix. And next is given by traveral way only.
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> mapp = {{" "},
        {""}, {"a","b","c"}, {"d","e","f"},
        {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"},
        {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}};
        vector<string> ans;
        if(digits.empty()) return ans;
        int idx = digits[0]-'0';
        for(int i = 0; i < mapp[idx].size(); ++i) {
            ans.push_back(mapp[idx][i]);
        }
        for(int i = 1; i < digits.length(); ++i) {
            vector<string> temp;
            idx = digits[i]-'0';
            for(int j = 0; j < ans.size(); ++j) {
                for(int k = 0; k < mapp[idx].size(); ++k) {
                    temp.push_back(ans[j] + mapp[idx][k]);
                }
            }
            ans = temp;
        }
        return ans;
    }
};

//==============================================================

int main()
{
    Solution solu;
    string digits = "23";
    vector<string> ans = solu.letterCombinations(digits);
    Print::print(ans);
    return 0;
}