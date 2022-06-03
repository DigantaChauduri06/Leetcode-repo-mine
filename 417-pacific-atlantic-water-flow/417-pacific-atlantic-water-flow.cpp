class Solution {
    int ROW, COL;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& H) {
        ROW = size(H), COL = size(H[0]);
        if(ROW == 0) return {};
        vector<vector<bool>> pac(ROW, vector<bool>(COL, false));
        vector<vector<bool>> atl(ROW, vector<bool>(COL, false));
        // first row (pacific) and last row (atlantic)
        for (int c = 0;c < COL;c++) {
            // pacific
            dfs(H, 0, c, pac, H[0][c]);
            // atlantic
            dfs(H, ROW-1, c, atl, H[ROW-1][c]);
        }
        // first col (pacific) and last col (atlantic)
        for (int r = 0;r < ROW;r++) {
            // pacific
            dfs(H, r, 0, pac, H[r][0]);
            // atlantic
            dfs(H, r, COL-1, atl, H[r][COL-1]);
        }
        vector<vector<int>> res;
        // Intersection of pacific and atlantic will be our answer
        for (int i = 0;i < ROW;i++) {
            for (int j = 0;j < COL;j++) {
                if (pac[i][j] and atl[i][j]) 
                    res.push_back({i, j});
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& H, int i, int j,  vector<vector<bool>> &seen, int prev) {
        if (i < 0 or
           j < 0 or
           i >= ROW or
           j >= COL or
           prev > H[i][j] or
           seen[i][j]) return;
        seen[i][j] = true;
        dfs(H, i+1, j, seen, H[i][j]);
        dfs(H, i-1, j, seen, H[i][j]);
        dfs(H, i, j+1, seen, H[i][j]);
        dfs(H, i, j-1, seen, H[i][j]);
    }
};