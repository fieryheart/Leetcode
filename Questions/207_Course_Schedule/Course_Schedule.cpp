#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    typedef struct Node {
        vector<int> to;
        int in = 0;
    }node;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        node graph[numCourses];
        vector<bool> visited(numCourses, false);
        int cnt = 0;
        for(int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i][1]].to.push_back(prerequisites[i][0]);
            graph[prerequisites[i][0]].in++;
        }
        while(true) {
            int v = -1;
            for(int i = 0; i < numCourses; ++i) {
                cout << i << " " << graph[i].in << endl;
                if(graph[i].in == 0 && !visited[i]) {
                    v = i;
                    break;
                }
            }
            if(v == -1) break;
            cnt++;
            visited[v] = true;
            cout << "v: " << v << endl;
            for(int i = 0; i < graph[v].to.size(); ++i) {
                graph[graph[v].to[i]].in--;
                // cout << "graph[v].to[i]" << graph[v].to[i] << endl;
            }
        }
        if(cnt == numCourses) return true;
        else return false;
    }
};

int main()
{
    vector<vector<int>> prerequisites = {{0,1},{0,2},{1,2}};
    Solution s;
    bool rst = s.canFinish(3, prerequisites);
    cout << "rst:" << rst << endl;
    return 0;
}