/*
 * @Author: fieryheart 
 * @Date: 2019-12-10 20:59:22 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-12-10 21:14:41
 * @Desc: Use the stack to maintain the special number like IX.
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    int romanToInt(string s) {
        vector<char> roman = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        vector<int> romanInt = {1, 5, 10, 50, 100, 500, 1000};
        stack<int> st;
        map<char, int> mapp;
        int ans = 0;
        for(int i = 0; i < roman.size(); ++i) {
            mapp[roman[i]] = romanInt[i];
        }
        for(int i = 0; i < s.length(); ++i) {
            int temp = mapp[s[i]];
            if(st.empty()) st.push(temp);
            else {
                if(temp <= st.top()){
                    ans += st.top();
                    st.pop();
                    while(!st.empty()) {
                        ans -= st.top();
                        st.pop();
                    }
                }
                st.push(temp);
            }
        }
        if(!st.empty()) {
            ans += st.top();
            st.pop();
            while(!st.empty()) {
                ans -= st.top();
                st.pop();
            }
        }
        return ans;
    }
};

//==============================================================

int main()
{
    string s = "MCMXCIV";
    Solution solu;
    int ans = solu.romanToInt(s);
    Print::print(ans);
    return 0;
}