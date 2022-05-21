class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                string strBoard = to_string(board[i][j]);
                string strRow = to_string(i);
                string strCol = to_string(j);
                
                string row = strBoard + " is in " + strRow + " th Row";
                string col = strBoard + " is in " + strCol + " th Col";
                string rowXcol = strBoard + " is in " + to_string(i/3) + " th Row " + to_string(j/3) + " th Col";
                if (board[i][j] != '.') {
                    if (st.find(row) != st.end() || st.find(col) != st.end() || st.find(rowXcol) != st.end()) {
                        return false;
                    }
                    
                }
                st.insert(row);
                st.insert(col);
                st.insert(rowXcol);
            }
        }
        return true;
    }
};