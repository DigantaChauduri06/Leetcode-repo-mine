class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    bfs(grid, i, j, m, n);
                }
            }
        }
        return cnt; 
    }
private:
    bool isInRange(int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    void bfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        queue<pair<int, int>> q;
        q.push({i,j});
        while (q.size() != 0) {
            auto f = q.front();
            q.pop();
            int x = f.first;
            int y = f.second; 
            grid[x][y] = '0';
            if (isInRange(x-1,y,m,n) && grid[x-1][y] == '1'){
                    grid[x-1][y] = '0';
                    q.push({x-1, y});
            }
            if (isInRange(x+1,y,m,n) && grid[x+1][y] == '1'){
                    grid[x+1][y] = '0';
                    q.push({x+1, y});
            }
            if (isInRange(x,y-1,m,n) && grid[x][y-1] == '1'){
                    grid[x][y-1] = '0';
                    q.push({x, y-1});
            }
            if (isInRange(x,y+1,m,n) && grid[x][y+1] == '1'){
                grid[x][y+1] = '0';
                q.push({x, y+1});
            }
        }
    }
};