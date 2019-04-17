#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        // 不够快
        int lengthOfLongestSubstring1(string s) {
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
        // 参考代码，9行
        int lengthOfLongestSubstring2(string s) {
            vector<int> ascii(128, -1);
            int maxl = 0, start = -1;
            for(int i = 0; i < s.length(); ++i) {
                if(ascii[s[i]] > start) start = ascii[s[i]];
                ascii[s[i]] = i;
                maxl = max(maxl, i-start);
            }
            return maxl;
        }
};


int main()
{
    string str = "abcabcbb";
    Solution s;
    int rst = s.lengthOfLongestSubstring1(str);
    cout << rst << endl;
    return 0;
}