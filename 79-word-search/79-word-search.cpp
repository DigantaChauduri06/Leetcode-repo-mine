class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word,i,j,m,n)) return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int m, int n) {
        if (word.size() == 0) return true;
        if (i >= m || j >= n || i < 0 || j < 0 || board[i][j] != word[0]) return false;
        char cur = board[i][j];
        board[i][j] = '*';
        string rem = word.substr(1);
        bool left = dfs(board, rem, i-1, j, m,n);
        bool right = dfs(board, rem, i+1, j, m,n);
        bool up = dfs(board, rem, i, j-1, m,n);
        bool down = dfs(board, rem, i, j+1, m,n);
        board[i][j] = cur;
        return left || right || up || down;
        
    }
};