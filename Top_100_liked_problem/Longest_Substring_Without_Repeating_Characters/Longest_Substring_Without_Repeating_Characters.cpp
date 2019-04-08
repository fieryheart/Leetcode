#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int maxl = 0, sub_num = 0, sub_start = 0, idx = 0;
            int ascii[127];
            vector<char> v;
            fill(ascii, ascii+127, -1);
            for(int i = 0; i < s.length(); ++i)
            {
                if(ascii[s[i] - ' '] == -1) {
                    v.push_back(s[i]);
                    ascii[s[i] - ' '] = idx++;
                    sub_num++;
                    if(sub_num > maxl) maxl = sub_num;
                } else {
                    i = sub_start + ascii[s[i] - ' '];
                    sub_start = i + 1;
                    if(sub_start + maxl >= s.length()) break;
                    sub_num = 0;
                    idx = 0;
                    for(int j = 0; j < v.size(); ++j) {
                        ascii[v[j] - ' '] = -1;
                    }
                    v.clear();
                }
            }
            return maxl;
        }
};


int main()
{
    string str = "abcabcbb";
    Solution s;
    int rst = s.lengthOfLongestSubstring(str);
    cout << rst << endl;
    return 0;
}