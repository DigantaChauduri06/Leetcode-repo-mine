class Solution {
    int ROW, COL;
    vector<pair<int, int>> dirs{{0, -1},{-1, 0}, {1, 0}, {0, 1}};
public:
    int numIslands(vector<vector<char>>& G) {
        ROW = size(G), COL = size(G[0]);
        int count = 0;
        for (int i = 0;i < ROW;i++) {
            for (int j = 0;j < COL;j++) {
                if (G[i][j] == '1') {
                    count += 1;
                    bfs(G, i, j);
                }
            }
        }
        return count;
    }
private:
    void bfs(vector<vector<char>> &G, int i, int j) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        G[i][j] = '0';
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int i = 0;i < 4;i++) {
                    int r = row + dirs[i].first;
                    int c = col + dirs[i].second;
                    if (!valid(G, r, c)) continue;
                    q.push(make_pair(r, c));
                    G[r][c] = '0';
                }
            }
        }
    }
    bool valid(vector<vector<char>> &G, int i, int j) {
        return i >= 0 and
            j >= 0 and
            i < ROW and
            j < COL and
            G[i][j] == '1';
    }
};