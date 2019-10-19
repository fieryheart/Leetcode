#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Team {
    int id;
    public:
        vector<int> wins;
        Team(int id, string match) {
            // printf("\nThe team%d: ", id);
            for(int i = 0; i < match.length(); ++i) {
                if(match[i] == 'W') {
                    wins.push_back(i);
                    // printf("%d ", i);
                }
            }
        }
};


class FoodChain {
    public:
        vector<vector<int>> chains;
        FoodChain(vector<Team> teams) {
            // cout << "\nThe food chain:";
            vector<int> chain;
            vector<bool> visit(teams.size(), false);
            dfs(teams, chain, visit, 0);
        }
        void display() {
            if(chains.empty() || chains[0].empty()) {
                cout << "No Solution" << endl;
            } else {
                for(int i = 0; i < chains[0].size(); ++i) {
                    if(i != 0) printf(" ");
                    printf("%d", chains[0][i]+1);
                }
                printf("\n");
            }
        }
        void dfs(vector<Team> &teams, vector<int> &chain, vector<bool> &visit, int t) {
            chain.push_back(t);
            visit[t] = true;
            bool flag = true;
            for(int i = 0; i < teams[t].wins.size(); ++i) {
                if(!visit[teams[t].wins[i]]) {
                    dfs(teams, chain, visit, teams[t].wins[i]);
                    flag = false;
                }
            }
            if(flag && chain.size() == teams.size()) {
                for(int i = 0; i < teams[t].wins.size(); ++i) {
                    if(teams[t].wins[i] == chain[0]) {
                        chains.push_back(chain);
                    }
                }
            }
            visit[t] = false;
            chain.pop_back();
        }

};

bool cmp(vector<int> q, vector<int> p) {
    for(int i = 0;i < q.size(); ++i) {
        if(q[i] != p[i]) {
            return q[i] < p[i];
        }
    }
    return true;
}

int main()
{
    int n;
    string s;
    cin >> n;
    vector<Team> v;
    for(int i = 0;i < n; ++i) {
        cin >> s;
        Team t = Team(i, s);
        v.push_back(t);
    }
    FoodChain* fc = new FoodChain(v);
    sort(fc->chains.begin(), fc->chains.end(),cmp);
    fc->display();
    return 0;
}