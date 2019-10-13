class Solution {
public:
    int numDecodings(string s) {
        vector<int> ans(s.length(), 0);
        int tmp;
        if(s.empty() || s[0] == '0') return 0;
        ans[0] = 1;
        if(s.length() == 1) return ans[0];
        tmp = stoi(s.substr(0,2));
        if(s[1] == '0') {
            if(tmp != 10 && tmp != 20) return 0;
            else ans[1] = ans[0];
        } else {
            if(tmp >= 10 && tmp <= 26) ans[1] = 2;
            else ans[1] = ans[0];
        }
        
        for(int i = 2; i < s.length(); ++i) {
            tmp = stoi(s.substr(i-1, 2));
            if(s[i] == '0') {
                if(tmp != 10 && tmp != 20) return 0;
                else ans[i] = ans[i-2];
            } else {
                if(tmp >= 10 && tmp <= 26) ans[i] = ans[i-1] + ans[i-2];
                else ans[i] = ans[i-1];
            }
        }
        return ans[s.length()-1];
    }
};