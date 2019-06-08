#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.empty()) return ans;
        sort(intervals.begin(), intervals.end(), [](vector<int> q, vector<int> p){return q[0] < p[0];});
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] > ans.back()[1]) ans.push_back(intervals[i]);
            else ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        return ans;
    }
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        if(intervals.empty()) return intervals;
        vector<vector<int>> temp;
        while(true) {
            queue<int> toMerge, unMerge;
            for(int i = 0; i < intervals.size(); ++i)
                toMerge.push(i);
            while(!toMerge.empty()) {
                int v = toMerge.front();
                toMerge.pop();
                int vl = intervals[v][0], vr = intervals[v][1];
                while(!toMerge.empty()) {
                    int w = toMerge.front();
                    toMerge.pop();
                    int wl = intervals[w][0], wr = intervals[w][1];
                    if((wl >= vl && wl <= vr)
                    || (wr >= vl && wr <= vr)
                    || (wl <= vl && wr >= vr)
                    || (wl >= vl && wr <= vr)) {
                        vl = min(vl, wl);
                        vr = max(vr, wr);
                    } else unMerge.push(w);
                }
                while(!unMerge.empty()) {
                    toMerge.push(unMerge.front());
                    unMerge.pop();
                }
                temp.push_back({vl, vr});
            }

            if(temp.size() == intervals.size()) break;
            intervals = temp;
            temp.clear();
        }
        return intervals;
    }
};
int main()
{
    vector<vector<int>> intervals = {{1,4},{0,0}};
    Solution s;
    vector<vector<int>> rst = s.merge1(intervals);
    for(int i = 0; i < rst.size(); ++i) {
        for(int j = 0; j < rst[i].size(); ++j) {
            cout << rst[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}