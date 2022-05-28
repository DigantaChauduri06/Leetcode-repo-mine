class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> seen(m, vector<bool>(n, false));
                    if (dfs(board, word,i,j,m,n, seen)) return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int m, int n, vector<vector<bool>> &seen) {
        if (word.size() == 0) return true;
        if (i >= m || j >= n || i < 0 || j < 0 || board[i][j] != word[0] || seen[i][j]) return false;
        seen[i][j] = true;
        string rem = word.substr(1);
        bool left = dfs(board, rem, i-1, j, m,n, seen);
        bool right = dfs(board, rem, i+1, j, m,n, seen);
        bool up = dfs(board, rem, i, j-1, m,n, seen);
        bool down = dfs(board, rem, i, j+1, m,n, seen);
        seen[i][j] = false;
        return left || right || up || down;
        
    }
};