#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int idxs = 0, idxp = 0;
        while(idxs < s.length() || idxp < p.length()) {
            if(idxp+1 < p.length() && p[idxp+1] == '*') {
                if(p[idxp] == '.') {
                    if(idxp+2 == p.length()) return true;
                    else {
                        bool flag = false;
                        for(int i = idxs; i < s.length(); ++i) {
                            if(s[i] == p[idxp+2]) {
                                flag = flag || this->isMatch(s.substr(i), p.substr(idxp+2));
                            }
                        }
                        return flag;
                    }
                }
                else if(s[idxs] == p[idxp]) {
                    int i_s = idxs, i_p = idxp+2, count_s = 0, count_p = 0;
                    while(i_s < s.length() && s[i_s] == p[idxp]) {
                        i_s++;
                        count_s++;
                    }
                    while(i_p < p.length() && p[i_p] == p[idxp]) {
                        i_p++;
                        count_p++;
                    }
                    if(count_s >= count_p) {
                        idxs = i_s;
                        idxp = i_p;
                    } else return false;
                } else {
                    idxp += 2;
                }
            } else {
                if(p[idxp] == '.' || s[idxs] == p[idxp]) {
                    idxs++;
                    idxp++;
                } else {
                    break;
                }
            }
        }
        if(idxs == s.length() && idxp == p.length()) {
            return true;
        } else {
            return false;
        }
    }
};
int main()
{
    string str = "aaa";
    string pat = "a*aaaa";
    Solution s;
    bool rst = s.isMatch(str, pat);
    cout << rst << endl;
    return 0;
}