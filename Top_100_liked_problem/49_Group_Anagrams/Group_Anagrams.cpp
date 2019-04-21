#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> mapp;
        for(int i = 0; i < strs.size(); ++i) {
            char ascii[26] = {0};
            string str = strs[i];
            string temp = "";
            for(int j = 0; j < str.length(); ++j) ascii[str[j]-'a']++;
            // cout << str << " " << temp << endl;
            for(int j = 0; j < 26; ++j) {
                if(ascii[j]) {
                    temp += ('a'+j);
                    temp += to_string(ascii[j]);
                }
            }
            mapp[temp].push_back(str);
        }
        for(auto it = mapp.begin(); it != mapp.end(); ++it) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> rst = s.groupAnagrams(strs);
    for(int i = 0; i < rst.size(); ++i) {
        for(int j = 0; j < rst[i].size(); ++j) {
            cout << rst[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}