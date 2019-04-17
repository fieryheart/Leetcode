#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome1(string s) {
        string s1 = "#";
        for(int i = 0; i < s.length(); i++)
        {
            s1 += s[i];
            s1 += "#";
        }
        s = s1;
        string rst = "";
        int maxl = -1;
        for(int i = 0; i < s.length(); ++i)
        {
            if(i + maxl >= (int)s.length()) break;
            int j = 0;
            while(i-j >= 0 && i+j < s.length() && s[i-j] == s[i+j]) j++;
            if(j) j--;
            if(j > maxl) {
                maxl = j;
                rst = s.substr(i-j, 2*j+1);
            }
        }
        s1 = "";
        for(int i = 0; i < rst.length(); ++i)
        {
            if(rst[i] == '#') continue;
            s1 += rst[i];
        }
        rst = s1;
        return rst;
    }
    string longestPalindrome2(string s) {
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

int main()
{
    string str = "cbbd";
    Solution s;
    string rst = s.longestPalindrome2(str);
    cout << rst << endl;
    return 0;
}