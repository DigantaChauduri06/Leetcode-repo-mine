class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ROW, COL, maxArea = len(grid), len(grid[0]), 0
        dx = [0,0,-1,1]
        dy = [1,-1,0,0]
        def inRange(i, j):
            return (i >= 0 
                    and j >= 0
                    and i < ROW
                    and j < COL
                    and grid[i][j] == 1)
        
        def bfs(r, c):
            q = deque()
            q.append((r, c))
            area = 0
            grid[r][c] = 2
            while len(q) > 0:
                x, y = q.popleft()
                area += 1
                for i in range(4):
                    row = x + dx[i]
                    col = y + dy[i]
                    if not inRange(row, col):
                        continue
                    q.append((row, col))
                    grid[row][col] = 2
            return area
        for i in range(ROW):
            for j in range(COL):
                if grid[i][j] == 1:
                    maxArea = max(maxArea, bfs(i,j))
        return maxArea