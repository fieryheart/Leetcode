#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int slen = s.length(), tlen = t.length(), start = 0, minL = INT_MAX, minS = -1, count = 0, temp_count = 0;
        map<char, int> tmapp, temp_mapp;
        for(int i = 0; i < tlen; ++i) {
            if(tmapp[t[i]] == 0) count++;
            tmapp[t[i]]++;
        }
        for(int i = 0; i < slen; ++i) {
            if(tmapp[s[i]]) {
                temp_mapp[s[i]]++;
                if(temp_mapp[s[i]] == tmapp[s[i]]) temp_count++;
                if(temp_count == count) {
                    while(tmapp[s[start]] == 0 || temp_mapp[s[start]] > tmapp[s[start]]) {
                        if(tmapp[s[start]]) temp_mapp[s[start]]--;
                        start++;
                    }
                    if(i - start + 1 < minL) {
                        minL = i - start + 1;
                        minS = start;
                    }
                    temp_mapp[s[start]]--;
                    temp_count--;
                    start++;           
                }
            }
        }
        if(minS == -1) return "";
        else return s.substr(minS, minL);
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