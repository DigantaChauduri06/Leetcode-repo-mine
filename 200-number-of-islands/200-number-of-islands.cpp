class Solution {
    int ROW, COL;
public:
    int numIslands(vector<vector<char>>& G) {
        ROW = size(G), COL = size(G[0]);
        int count = 0;
        for (int i = 0;i < ROW;i++) {
            for (int j = 0;j < COL;j++) {
                if (G[i][j] == '1') {
                    count += 1;
                    dfs(G, i, j);
                }
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<char>> &G, int i, int j) {
        if (valid(G, i, j)) {
            G[i][j] = '0';
            // call in all dirs
            dfs(G, i+1, j);
            dfs(G, i-1, j);
            dfs(G, i, j+1);
            dfs(G, i, j-1);
        } else return;
    }
    bool valid(vector<vector<char>> &G, int i, int j) {
        return i >= 0 and
            j >= 0 and
            i < ROW and
            j < COL and
            G[i][j] == '1';
    }
};