class Solution {
    int ROW, COL;
public:
    void setZeroes(vector<vector<int>>& mat) {
        bool rowZero = false, colZero = false;
        ROW = size(mat), COL = size(mat[0]);
        for (int i = 0;i < ROW;i++) {
            if (mat[i][0] == 0) rowZero = true;
        }
        for (int i = 0;i < COL;i++) {
            if (mat[0][i] == 0) colZero = true;
        }
        for (int i = 1;i < ROW;i++) {
            for (int j = 1;j < COL;j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        for (int i = 1;i < COL;i++) {
            if (mat[0][i] == 0) {
                nullifyROW(mat, i);
            }
        }
        for (int i = 1;i < ROW;i++) {
            if (mat[i][0] == 0) {
                nullifyCOL(mat, i);
            }
        }
        if (rowZero) {
            nullifyROW(mat, 0);
        }
        if (colZero) {
            nullifyCOL(mat, 0);
        }
    }
private:
    void nullifyROW(vector<vector<int>> &mat, int i) {
        for (int j = 0;j < ROW;j++) {
            mat[j][i] = 0;
        }
    }
    void nullifyCOL(vector<vector<int>> &mat, int i) {
        for (int j = 0;j < COL;j++) {
            mat[i][j] = 0;
        }
    }
};