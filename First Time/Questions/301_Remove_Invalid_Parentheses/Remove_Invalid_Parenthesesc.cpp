class Solution {
private: 
    bool isValid(string s) {
        int num = 0;
        for(char &c : s) {
            if(c == '(') num++;
            else if(c == ')') {
                if(num) num--;
                else return false;
            }
        }
        return true;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int num1 = 0, num2 = 0;
        for(char& c : s) {
            if(c == '(') num1++;
            else if(c == ')') {
                if(num1) num1--;
                else num2++;
            }
        }
        vector<string> ans;
        remove(s, 0, num1, num2, ans);
        return ans;
    }
    void remove(string s, int start, int num1, int num2, vector<string> &ans) {
        if(num1 == 0 && num2 == 0 && isValid(s)) {
            ans.push_back(s);
        } else {
            for(int i = start; i < s.length(); ++i) {
                string tmp = s;
                if(num1 > 0 && s[i] == '(' && (i == start || s[i] != s[i-1])) {
                    tmp.erase(i, 1);
                    remove(tmp, i, num1-1, num2, ans);
                }
                if(num2 > 0 && s[i] == ')' && (i == start || s[i] != s[i-1])) {
                    tmp.erase(i, 1);
                    remove(tmp, i, num1, num2-1, ans);
                }
            }
        }
    }
};