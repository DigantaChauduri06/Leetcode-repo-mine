class Solution {
    int ROW, COL;
public:
    void setZeroes(vector<vector<int>>& mat) {
        bool isZero = (mat[0][0] == 0);
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
                //cout << "nullify" << endl;
                nullifyROW(mat, i);
            }
        }
        for (int i = 1;i < ROW;i++) {
            if (mat[i][0] == 0) {
                nullifyCOL(mat, i);
            }
        }
        // if (isZero) {
        //     nullifyROW(mat, 0);
        //     nullifyCOL(mat, 0);
        // }
        if (rowZero) {
            for (int i = 0;i < ROW;i++) {
                mat[i][0] = 0;
            }
        }
        if (colZero) {
            cout << "nullify";
            for (int i = 0;i < COL;i++) {
                mat[0][i] = 0;
            }
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
/*
[
    [1,2,3,4],
    [5,0,7,8],
    [0,10,11,12],
    [13,14,15,0]
]

*/