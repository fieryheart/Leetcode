/*
 * @Author: fieryheart 
 * @Date: 2019-11-23 14:45:34 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-11-23 15:14:10
 * @Desc: if considering all boundary conditions well, it will be easy.
 */

#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    int reverse(int x) {
        bool flag = true;
        string from = to_string(x);
        if(from[0] == '-') {
            from = from.substr(1);
            flag = false;
        }
        string str_max = to_string(INT_MAX);
        string str_min = to_string(INT_MIN).substr(1);
        string to = "";
        for(auto it = from.rbegin(); it != from.rend(); it++) {
            // Print::print(*it);
            to += *it;
        }
        while(to.length() > 1 && to[0] == '0') to = to.substr(1);
        if(flag && to.length() >= str_max.length() && to > str_max) return 0;
        if(!flag && to.length() >= str_min.length() && to > str_min) return 0;
        x = stoi(to);
        return flag ? x : -x;
    }
};

//==============================================================

int main()
{
    int x = 0;
    Solution solu;
    int ans = solu.reverse(x);
    Print::print(ans);
    return 0;
}