class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        ROW,COL = len(grid),len(grid[0])
        def helper(i,j):
            if i == ROW:
                return j
            if grid[i][j] == 1 and j+1 < COL and grid[i][j+1] == 1:
                return helper(i+1,j+1)
            elif grid[i][j] == -1 and j-1 >= 0 and grid[i][j-1] == -1:
                return helper(i+1,j-1)
            else:
                return -1
        return [helper(0,j) for j in range(len(grid[0]))]