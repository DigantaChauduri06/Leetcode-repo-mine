class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose The matrix
        int n = size(matrix);
        int m = size(matrix[0]);
        if (n == 1) return;
        for (int i = 0;i < n;i++) {
            for (int j = i;j < n;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
       // 2-pointer approch
        for (int i = 0;i < n;i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};