typedef struct Node {
    int x, y;
}node;
bool myCmp(node q, node p) {
    return q.y > p.y;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mapp;
        vector<node> q;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            mapp[nums[i]]++;
        }
        for(auto it = mapp.begin(); it != mapp.end(); ++it) {
            q.push_back({it->first, it->second});
        }
        sort(q.begin(), q.end(), myCmp);
        for(int i = 0; i < k; ++i) {
            ans.push_back(q[i].x);
        }
        return ans;
    }
};