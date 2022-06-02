class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mx = 0;
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == 1) {
                   int cnt = dfs(grid, i, j, m, n);
                    mx = max(mx, cnt);
                }
            }
        }
        return mx;
    }
private:
    bool inRange(vector<vector<int>> &grid,int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n) && (grid[i][j] == 1);
    }
    int dfs(vector<vector<int>> &grid, int i,int j,int m, int n) {
        if (inRange(grid, i,j,m,n)) {
            grid[i][j] = 0;
            return 1 + dfs(grid,i+1,j, m, n) +
                dfs(grid, i-1, j,m, n) +
                dfs(grid, i, j+1, m, n) +
                dfs(grid, i, j-1,m, n);
        } else return 0;
    }
};