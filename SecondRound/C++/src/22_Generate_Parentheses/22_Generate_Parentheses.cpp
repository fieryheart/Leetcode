/*
 * @Author: fieryheart 
 * @Date: 2019-12-15 21:06:55 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-15 21:24:36
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string p = "";
        generate(ans, p, n, n);
        return ans;
    }
    void generate(vector<string> &ans, string p, int left, int right) {
        if(!left && !right) {
            ans.push_back(p);
            return;
        }
        if(left > 0) generate(ans, p+'(', left-1, right);
        if(right > left) generate(ans, p+')', left, right-1);
    }
};

//==============================================================

int main()
{
    int n = 3;
    Solution solu;
    vector<string> ans = solu.generateParenthesis(n);
    Print::print(ans);
    return 0;
}