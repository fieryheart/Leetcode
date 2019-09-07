class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, radius;
        if(s.empty()) return ans;
        vector<char> ch;
        for(int i = 0; i < s.length(); ++i) {
            ch.push_back(s[i]);
            ch.push_back('#');
        }
        ch.pop_back();
        for(int i = 0; i < ch.size(); ++i) {
            if(ch[i] == '#') radius = 1;
            else radius = 0;
            while(i - radius >= 0 && i + radius < ch.size() && ch[i-radius] == ch[i+radius]) {
                radius += 2;
                ans++;
            }
        }
        return ans;
    }
};