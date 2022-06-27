class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ROW, COL, maxArea = len(grid), len(grid[0]), 0
        dx = [0,0,-1,1]
        dy = [1,-1,0,0]
        def dfs(r, c):
            if r < 0 or c < 0 or r >= ROW or c >= COL or grid[r][c] != 1:
                return 0
            grid[r][c] = 2
            val = 0
            for i in range(4):
                val += dfs(r+dx[i],c+dy[i])
            return val + 1
        
        for i in range(ROW):
            for j in range(COL):
                if grid[i][j] == 1:
                    maxArea = max(maxArea, dfs(i,j))
        return maxArea