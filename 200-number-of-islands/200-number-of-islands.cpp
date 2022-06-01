class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == '1') {
                    cout << cnt << endl;
                    cnt++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return cnt;
    }
private:
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
        if (i == m || j == n || i < 0 || j < 0 || grid[i][j] != '1') 
            return;
        grid[i][j] = '2';
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
        return;
    }
};