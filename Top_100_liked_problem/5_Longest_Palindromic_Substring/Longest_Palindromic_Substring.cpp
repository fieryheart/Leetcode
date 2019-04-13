#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
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
};

int main()
{
    string str = "cbbd";
    Solution s;
    string rst = s.longestPalindrome(str);
    cout << rst << endl;
    return 0;
}