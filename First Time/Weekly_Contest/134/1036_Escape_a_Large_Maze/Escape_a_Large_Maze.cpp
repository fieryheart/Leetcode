#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int direction[4][2] = {{0,-1}, {1, 0}, {0,1}, {-1, 0}};
typedef pair<int,int> ii;
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        queue<ii> q;
        q.push(ii{source[0], source[1]});
        int limit = 5e4;
        set<ii> visit;
        for(int i = 0; i < blocked.size(); ++i)
            visit.insert(ii{blocked[i][0], blocked[i][1]});
        
        while(!q.empty() && limit--) {
            ii nd = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int x = nd.first + direction[i][0];
                int y = nd.second + direction[i][1];
                if(x == -1 || x == 1e6 || y == -1 || y == 1e6) continue;
                if(visit.count(ii{x,y})) continue;
                q.push(ii{x, y});
                visit.insert({x, y});
                if(x == target[0] && y == target[1]) 
                    limit = 0;
            }
        }
        return limit <= 0;
    }
};
int main()
{
    vector<vector<int>> blocked = {};
    vector<int> source = {0, 0};
    vector<int> target = {999999, 999999};
    Solution s;
    cout << "init" << endl;
    bool rst = s.isEscapePossible(blocked, source, target);
    cout << rst << endl;
    return 0;
}