#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    typedef struct node {
        char c;
        int i;
    }node;
    int longestValidParentheses(string s) {
        stack<node> st;
        vector<bool> v(s.length(), false);
        for(int i = 0; i < s.length(); ++i)
        {
            if(!st.empty() && s[i] == ')') {
                if(st.top().c != '(') {
                    st.push({s[i], i});
                } else {
                    v[st.top().i] = v[i] = true;
                    st.pop();
                }
            } else st.push({s[i], i});
        }
        int count_temp = 0, count_max = 0;
        for(int i = 0; i < v.size(); ++i) {
            if(v[i]) count_temp++;
            else {
                count_max = max(count_max, count_temp);
                count_temp = 0;
            }
        }
        count_max = max(count_max, count_temp);
        return count_max;
    }
};
int main()
{
    string str = "()(()";
    Solution s;
    int rst = s.longestValidParentheses(str);
    cout << rst << endl;
    return 0;
}