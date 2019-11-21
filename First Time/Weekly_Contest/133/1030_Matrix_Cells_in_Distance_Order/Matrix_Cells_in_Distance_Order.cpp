bool cmp(vector<int> q, vector<int> p) {
    return q[2] < p[2];
}
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> temp, ans;
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                vector<int> v = {i, j, abs(i-r0)+abs(j-c0)};
                temp.push_back(v);
            }
        }
        sort(temp.begin(), temp.end(), cmp);
        for(int i = 0; i < temp.size(); ++i) {
            vector<int> v = {temp[i][0], temp[i][1]};
            ans.push_back(v);
        }
            
        return ans;
    }
};