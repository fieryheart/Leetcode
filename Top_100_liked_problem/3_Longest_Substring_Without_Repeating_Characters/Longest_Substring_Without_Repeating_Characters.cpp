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

            // keep track of the most recent index of each letter
            vector<int> ascii(128, -1);

            // keep track of the starting index of the current substring
            int maxl = 0, start = -1;

            for(int i = 0; i < s.length(); ++i) {

                // to ensure the letter in the subtring is not counted twice, the starting index of substring is 1 + (the last index of this letter)
                if(ascii[s[i]] > start) start = ascii[s[i]];

                // update the last recorded index of this letter to the most recent index
                ascii[s[i]] = i;

                // indices of current substring is (start, i]
                maxl = max(maxl, i-start);
            }
            return maxl;
        }


        int lengthOfLongestSubstring3(string s) {
            int left = 0, maxn = 0, tmp = 0;
            int ascii[128];
            fill(ascii, ascii+128, -1);
            for(int i = 0; i < s.length(); ++i) {
                tmp = s[i] - ' ';
                left = ascii[tmp] >= left ? ascii[tmp]+1 : left;
                ascii[tmp] = i;
                maxn = max(maxn, i - left + 1);
            }
            return maxn;
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