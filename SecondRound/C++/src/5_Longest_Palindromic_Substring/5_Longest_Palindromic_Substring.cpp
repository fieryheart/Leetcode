/*
 * @Author: fieryheart 
 * @Date: 2019-11-23 13:51:19 
 * @Last Modified by: fiery
 * @Last Modified time: 2019-11-23 15:14:34
 * @Desc: the key of solving the problem is to take account into the repeat number of center part of palindromic substring.
 * Firstly remove the repeat number of center part, then check whether two sides of subtring is equal.
 */

#include "../../lib/Root.h"

//==============================================================

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() < 2) return s;
        int maxl = 0, start = 0;
        for(int i = 0; s.length() - i > maxl / 2; ) {
            int left, right;
            left = right = i;
            while(right+1 < s.length() && s[right+1] == s[right]) right++;
            i = right+1;
            while(right+1 < s.length() && left > 0 && s[left-1] == s[right+1]) {
                left--;
                right++;
            }
            if(right-left+1 > maxl) {
                maxl = right-left+1;
                start = left;
            }
            
        }
        return s.substr(start, maxl);        
    }
};

//==============================================================

int main()
{
    string s = "babad";
    Solution solu;
    string ans = solu.longestPalindrome(s);
    Print::print(ans);
    return 0;
}