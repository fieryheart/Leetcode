bool cmp(vector<int> p, vector<int> q) {
    return p[0] != q[0] ? p[0] > q[0] : p[1] < q[1]; 
}
class Solution {
public:
    void swapVector(vector<vector<int>> &people, int i, int j) {
            vector<int> temp;
            temp = people[i];
            people[i] = people[j];
            people[j] = temp;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        int p = 1;
        /*
        while(p < people.size() && people[p][0] == people[p-1][0]) p++;
        for(int i = p; i < people.size(); ++i) {
            for(int j = people[i][1]; j < i; ++j){
                swapVector(people, i, j);
            }
        }
        */
        vector<vector<int>> ans;
        for(auto person : people) ans.insert(ans.begin()+person[1], person);
        return ans;
    }
};