class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n, cnt = len(grid), len(grid[0]),0
        
        def dfs(i,j):
            if (i < 0 or j < 0 or i >= m or j >= n or grid[i][j] != '1') :
                return
            grid[i][j] = '0'
            # down
            dfs(i+1,j)
            # up
            dfs(i-1,j)
            # left
            dfs(i,j-1)
            # right
            dfs(i,j+1)
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    cnt += 1
                    dfs(i,j)
        return cnt