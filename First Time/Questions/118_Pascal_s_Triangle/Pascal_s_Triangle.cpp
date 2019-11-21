class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0) return ans;
        ans.push_back({1});
        for(int i = 2; i <= numRows; ++i) {
            vector<int> temp, back;
            temp.push_back(1);
            if(!ans.empty()) back = ans.back();
            for(int j = 1; j < back.size(); ++j) {
                temp.push_back(back[j-1]+back[j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};