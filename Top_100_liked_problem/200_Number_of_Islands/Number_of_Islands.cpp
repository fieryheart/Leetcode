class Solution {
public:
    typedef struct Node {
        int x;
        int y;
    }node;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(visit[i][j] == false && grid[i][j] == '1') {
                    
                    cnt++;
                    queue<node> q;
                    q.push({i, j});
                    visit[i][j] = true;
                    while(!q.empty()) {
                        node v = q.front();
                        q.pop();
                        int x = v.x, y = v.y;
                        if(x-1 >= 0 && grid[x-1][y] == '1' && !visit[x-1][y]) {
                            q.push({x-1, y});
                            visit[x-1][y] = true;
                        }
                        if(x+1 < n  && grid[x+1][y] == '1' && !visit[x+1][y]) {
                            q.push({x+1, y});
                            visit[x+1][y] = true;
                        }
                        if(y-1 >= 0 && grid[x][y-1] == '1' && !visit[x][y-1]) {
                            q.push({x, y-1});
                            visit[x][y-1] = true; 
                        }
                        if(y+1 < m  && grid[x][y+1] == '1' && !visit[x][y+1]) {
                            q.push({x, y+1});
                            visit[x][y+1] = true;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};