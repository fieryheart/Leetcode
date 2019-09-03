class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int set_number = 1;
        map<string, int> sett;
        map<string, double> variables;
        map<string, bool> mapp;
        for(int i = 0; i < equations.size(); ++i) {
            if(!mapp[equations[i][0]] && !mapp[equations[i][1]]) {
                mapp[equations[i][0]] = true;
                mapp[equations[i][1]] = true;
                variables[equations[i][1]] = 1.0;
                variables[equations[i][0]] = 1.0 * values[i];
                sett[equations[i][0]] = set_number;
                sett[equations[i][1]] = set_number;
                set_number++;
            } else if (mapp[equations[i][0]] && !mapp[equations[i][1]]) {
                variables[equations[i][1]] = variables[equations[i][0]] / values[i];
                sett[equations[i][1]] = sett[equations[i][0]];
                mapp[equations[i][1]] = true;
            } else if (!mapp[equations[i][0]] && mapp[equations[i][1]]) {
                variables[equations[i][0]] = variables[equations[i][1]] * values[i];
                sett[equations[i][0]] = sett[equations[i][1]];
                mapp[equations[i][0]] = true;
            } else if (mapp[equations[i][0]] / mapp[equations[i][1]] != values[i]) {
                int from_set = sett[equations[i][0]], to_set = sett[equations[i][1]];
                double scale = variables[equations[i][1]] * values[i] / variables[equations[i][0]];
                for(auto it = sett.begin(); it != sett.end(); ++it) {
                    if(it->second == from_set) {
                        it->second = to_set;
                        variables[it->first] *= scale;
                    }
                }
            }
        }
        
        vector<double> ans;
        for(int i = 0; i < queries.size(); ++i) {
            if(!mapp[queries[i][0]] || !mapp[queries[i][1]]
            || sett[queries[i][0]] != sett[queries[i][1]]) ans.push_back(-1.0);
            else ans.push_back(variables[queries[i][0]] / variables[queries[i][1]]);
        }
        
        return ans;
    }
};