class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& g) {
        int row = g.size(), col = g[0].size();
        if(row == 0) return {};
        vector<vector<int>> ans;
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        vector<vector<bool>> pacafic(row, vector<bool>(col, false));
        for(int i=0; i<col; i++)
        {
            dfs(g, pacafic, INT_MIN, 0, i);
            dfs(g, atlantic, INT_MIN, row-1, i);
        }
        for(int i=0; i<row; i++)
        {
            dfs(g, pacafic, INT_MIN, i, 0);
            dfs(g, atlantic, INT_MIN, i, col-1);
        }
        for (int i = 0;i < row;i++) {
            for (int j = 0;j < col;j++) {
                if (atlantic[i][j] && pacafic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int prev, int i, int j)
    {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || prev > matrix[i][j] || visited[i][j]) return;
        
        visited[i][j] = true;
        dfs(matrix, visited, matrix[i][j], i+1, j);
        dfs(matrix, visited, matrix[i][j], i-1, j);
        dfs(matrix, visited, matrix[i][j], i, j+1);
        dfs(matrix, visited, matrix[i][j], i, j-1);
    }
};