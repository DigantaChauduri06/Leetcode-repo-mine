class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mx = 0;
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == 1) {
                   int cnt = bfs(grid, i, j, m, n);
                    mx = max(mx, cnt);
                }
            }
        }
        return mx;
    }
private:
    bool inRange(int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    int bfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        int cnt = 0;
        if (i < 0 || j < 0 || i >= m || j >= n)
            return cnt;
        queue<pair<int, int>> q;
        q.push({i,j});
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            int x = f.first;
            int y = f.second;
            cnt++;
            grid[x][y] = 0;
           if (inRange(x-1,y,m,n) && grid[x-1][y] == 1){
                    grid[x-1][y] = 0;
                    q.push({x-1, y});
            }
            if (inRange(x+1,y,m,n) && grid[x+1][y] == 1){
                    grid[x+1][y] = 0;
                    q.push({x+1, y});
            }
            if (inRange(x,y-1,m,n) && grid[x][y-1] == 1){
                    grid[x][y-1] = 0;
                    q.push({x, y-1});
            }
            if (inRange(x,y+1,m,n) && grid[x][y+1] == 1){
                grid[x][y+1] = 0;
                q.push({x, y+1});
            }
        }
        return cnt;
    }
};