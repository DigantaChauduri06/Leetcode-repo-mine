class Solution {
    int ROW, COL;
public:
    int orangesRotting(vector<vector<int>>& G) {
        ROW = size(G), COL = size(G[0]);
        int fresh = 0, time = 0;
        queue<pair<int, int>> q;
        // Track how many fresh and rotten orenges
        for (int i = 0;i < ROW; i++) {
            for (int j = 0;j < COL; j++) {
                if (G[i][j] == 1) {
                    fresh++;
                }
                if (G[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }
        // Run BFS to mark adjacent orenges rotten
        while (!q.empty() && fresh) {
            int size = q.size();
            while (size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if (inRange(G, r+1, c)) {
                    q.push(make_pair(r+1, c));
                    G[r+1][c] = 2;
                    fresh--;
                }
                if (inRange(G, r-1, c)) {
                    q.push(make_pair(r-1, c));
                    G[r-1][c] = 2;
                    fresh--;
                }
                if (inRange(G, r, c+1)) {
                    q.push(make_pair(r, c+1));
                    G[r][c+1] = 2;
                    fresh--;
                }
                if (inRange(G, r, c-1)) {
                    q.push(make_pair(r, c-1));
                    G[r][c-1] = 2;
                    fresh--;
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
private:
    bool inRange(vector<vector<int>>& G, int r, int c) {
        return r >= 0 &&
            c >= 0 &&
            r < ROW &&
            c < COL && 
            G[r][c] == 1;
            
    }
};