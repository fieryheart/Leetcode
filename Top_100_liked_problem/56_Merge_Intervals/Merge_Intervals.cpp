#include <iostream>
#include <vector>
#include <algorithm>
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
};
int main()
{
    vector<vector<int>> intervals = {{1,4},{0,0}};
    Solution s;
    vector<vector<int>> rst = s.merge(intervals);
    for(int i = 0; i < rst.size(); ++i) {
        for(int j = 0; j < rst[i].size(); ++j) {
            cout << rst[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}