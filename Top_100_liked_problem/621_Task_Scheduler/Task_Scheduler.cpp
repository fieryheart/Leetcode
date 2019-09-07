class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mapp;
        int count = 0, ans = 0;
        for(auto t : tasks) {
            mapp[t]++;
            count = max(count, mapp[t]);
        }
        ans += (count-1)*(n+1);
        for(auto t : mapp)
            if(t.second == count)
                ans++;
        return max((int)tasks.size(), ans);
    }
};