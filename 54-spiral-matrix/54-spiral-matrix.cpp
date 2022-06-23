class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = size(mat);
        int n = size(mat[0]);
        int dir = 0;
        int left = 0, right = n - 1, top = 0, down = m - 1;
        while (left <= right && top <= down) {
            if (dir == 0) {
                for (int i = left;i <= right;i++) {
                     ans.push_back(mat[top][i]);  
                }
                top++;
            }
            if (dir == 1) {
                for (int i = top;i <= down;i++) {
                     ans.push_back(mat[i][right]);  
                }
                right--;
            }
            if (dir == 2) {
                for (int i = right;i >= left;i--) {
                    ans.push_back(mat[down][i]);
                }
                down--;
            }
            if (dir == 3) {
                for (int i = down;i >= top;i--) {
                     ans.push_back(mat[i][left]);  
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};