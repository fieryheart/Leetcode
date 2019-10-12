#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<char> letter[10] = { {},
                                {},
                                {'a', 'b', 'c'},
                                {'d', 'e', 'f'},
                                {'g', 'h', 'i'},
                                {'j', 'k', 'l'},
                                {'m', 'n', 'o'},
                                {'p', 'q', 'r', 's'},
                                {'t', 'u', 'v'},
                                {'w', 'x', 'y', 'z'}};
    void letterDFS(vector<string> &rst, string s, string digit, int idx) {
        if(idx == digit.length()) {
            rst.push_back(s);
            return;
        }
        int temp = digit[idx]-'0';
        for(int i = 0; i < letter[temp].size(); ++i)
        {
            this->letterDFS(rst, s+letter[temp][i], digit, idx+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> rst;
        if(digits.length()) this->letterDFS(rst, "", digits, 0);
        return rst;
    }
    
};
int main()
{
    string digits = "";
    Solution s;
    vector<string> rst = s.letterCombinations(digits);
    for(int i = 0; i < rst.size(); ++i)
    {
        cout << rst[i] << " ";
    }
    cout << endl;
    return 0;
}