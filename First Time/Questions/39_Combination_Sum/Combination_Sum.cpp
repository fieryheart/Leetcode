#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void combination(vector<vector<int>> &ans, vector<int> &temp, vector<int> &candidates, int idx, int sum, int target) {
        if(sum > target) return;
        else if(sum == target) ans.push_back(temp);
        for(int i = idx; i < candidates.size(); ++i) {
            if(candidates[i] <= target) {
                temp.push_back(candidates[i]);
                combination(ans, temp, candidates, i, sum+candidates[i], target);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(ans, temp, candidates, 0, 0, target);
        return ans;
    }
};
int main()
{
    vector<int> candidates = {2,3,5};
    int target = 8;
    Solution s;
    vector<vector<int>> rst = s.combinationSum(candidates, target);
    for(int i = 0; i < rst.size(); ++i) {
        for(int j = 0; j < rst[i].size(); ++j) {
            cout << rst[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}