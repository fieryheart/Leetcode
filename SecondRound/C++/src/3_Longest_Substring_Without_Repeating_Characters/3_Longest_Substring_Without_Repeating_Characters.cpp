/*
 * @Author: fieryheart 
 * @Date: 2019-11-22 18:40:44 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-11-23 15:14:54
 * @Desc: Use the hash table to keep the idx of item of substring, if the value of item in the hash table is after the left, then update left and the max length.
 */
#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
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

//==============================================================

int main()
{
    string s = "abcabcbb";
    Solution solu;
    int ans = solu.lengthOfLongestSubstring(s);
    Print::print(ans);
    return 0;
}