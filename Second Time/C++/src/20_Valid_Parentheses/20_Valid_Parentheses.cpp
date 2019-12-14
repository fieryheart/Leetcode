/*
 * @Author: fieryheart 
 * @Date: 2019-12-13 21:34:44 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-13 21:54:26
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else {
                if(st.empty()) return false;
                else {
                    if((s[i] == ')' && st.top() != '(') ||
                       (s[i] == ']' && st.top() != '[') ||
                       (s[i] == '}' && st.top() != '{')) return false;
                    else st.pop();
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};

//==============================================================

int main()
{
    string s = "([)]";
    Solution solu;
    bool ans = solu.isValid(s);
    Print::print(ans);
    return 0;
}