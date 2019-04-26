#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> sascii, tascii;
        for(int i = 0; i < t.length(); ++i)
            tascii[t[i]]++;
        for(int i = 0; i < s.length(); ++i)
            if(tascii[s[i]])
                sascii[s[i]]++;
        for(auto it = tascii.begin(); it != tascii.end(); ++it)
            if(it->second > sascii[it->first])
                return "";
        int start = 0, endd = s.length()-1;
        while(start <= endd) {
            if(tascii[s[start]] && sascii[s[start]] == tascii[s[start]]) break;
            if(tascii[s[start]]) sascii[s[start]]--;
            start++;
        }
        while(endd >= start) {
            if(tascii[s[endd]] && sascii[s[endd]] == tascii[s[endd]]) break;
            if(tascii[s[endd]]) sascii[s[endd]]--;
            endd--;
        }
        if(start <= endd) return s.substr(start, endd-start+1);
        else return "";
    }
};
int main()
{
    string s = "a", t = "ab";
    Solution slt;
    string rst = slt.minWindow(s, t);
    cout << rst << endl;
    return 0;
}