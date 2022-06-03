class Solution {
    int ROW,COL;
public:
    void solve(vector<vector<char>>& board) {
        ROW = size(board), COL = size(board[0]);
        // Capture the unsurrounded Regions ("O" -> "T")
        for (int i = 0;i < ROW;i++) {
            for (int j = 0;j < COL;j++) {
                // edges
                if (board[i][j] == 'O' && 
                   (i == 0 || j == 0 || i == ROW-1 || j == COL-1))
                    dfs(board, i, j);
            }
        }
        // Mark "X" to all Surrounded Regions
        for (int i = 0;i < ROW;i++) {
            for (int j = 0;j < COL;j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        // Mark "T" to "O"
        for (int i = 0;i < ROW;i++) {
            for (int j = 0;j < COL;j++) {
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
private:
    void dfs(vector<vector<char>> &board, int i, int j) {
        if (i < 0 
            || j < 0 
            || i >= ROW 
            || j >= COL 
            || board[i][j] != 'O') return;
        board[i][j] = 'T';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
    }
};