class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        bool flag = true;
        int plen = p.length(), slen = s.length();
        if(plen > slen) return ans;
        int p_set[26] = {0}, s_set[26] = {0};
        for(int i = 0; i < plen; ++i) {
            p_set[p[i] - 'a']++;
            s_set[s[i] - 'a']++;
        }
        for(int i = 0; i < 26 && flag; ++i) {
            if(p_set[i] != s_set[i]) flag = false;
        }
        if(flag) ans.push_back(0);
        for(int i = plen; i < slen; ++i) {
            if(flag && s[i] == s[i-plen]) ans.push_back(i-plen+1);
            else {
                s_set[s[i-plen] - 'a']--;
                s_set[s[i] - 'a']++;
                flag = true;
                for(int j = 0; j < 26 && flag; ++j) {
                    if(p_set[j] != s_set[j]) flag = false;
                }
                if(flag) ans.push_back(i-plen+1);
            }
        }
        return ans;
    }
};