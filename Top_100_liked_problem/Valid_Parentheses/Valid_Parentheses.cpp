#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); ++i)
        {
            if((s[i] == ')' && (st.empty() || st.top() != '('))
            || (s[i] == ']' && (st.empty() || st.top() != '['))
            || (s[i] == '}' && (st.empty() || st.top() != '{'))) return false;
            if(s[i] == ')' || s[i] == ']' || s[i] == '}') st.pop();
            else st.push(s[i]);
        }
        if(!st.empty()) return false;
        else return true;
    }
};
int main()
{
    string str = "[";
    Solution s;
    bool rst = s.isValid(str);
    cout << rst << endl;
    return 0;
}