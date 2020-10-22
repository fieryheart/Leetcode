#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
        
        int start = -1, endd = -1, ver_num = wordList.size();
        for(int i = 0; i < wordList.size(); ++i) {
            if(wordList[i] == endWord) endd = i;
            if(wordList[i] == beginWord) start = i;
        }
        if(endd == -1) return 0;
        if(start == -1) {
            wordList.push_back(beginWord);
            ver_num = wordList.size();
            start = ver_num-1;
        }
        // cout << start << " " << endd << endl;

        vector<vector<int>> graph(ver_num);
        for(int i = 0; i < ver_num; ++i) {
            for(int j = i+1; j < ver_num; ++j) {
                if(isLink(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        // for(int i = 0; i < graph.size(); ++i) {
        //     for(int j = 0; j < graph[i].size(); ++j) {
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        vector<int> dst(ver_num, INT_MAX);
        vector<bool> visit(ver_num, false);
        dst[start] = 0;
        while(true) {
            int v = -1, minn = INT_MAX;
            for(int i = 0; i < dst.size(); ++i) {
                if(!visit[i] && dst[i] < minn) {
                    minn = dst[i];
                    v = i;
                }
            }
            if(v == -1) break;
            visit[v] = true;
            for(int i = 0; i < graph[v].size(); ++i) {
                if(dst[v] + 1 < dst[graph[v][i]]) {
                    dst[graph[v][i]] = dst[v] + 1;
                }
            }
        }
        // for(int i = 0; i < ver_num; ++i) {
        //     cout << dst[i] << " ";
        // }
        // cout << endl;
        if(dst[endd] == INT_MAX) return 0;
        else return dst[endd]+1;
    }
    bool isLink(string w1, string w2) {
        int cnt = 0;
        for(int i = 0;i < w1.length(); ++i) {
            if(w1[i] != w2[i]) cnt++;
        }
        if(cnt == 1) return true;
        else return false;
    }
};

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution s;
    int ans = s.ladderLength1(beginWord, endWord, wordList);
    cout << ans << endl;
    return 0;
}