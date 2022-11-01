class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        ROW,COL = len(grid),len(grid[0])
        def helper(r,c,pc):
            i = 0
            if r == ROW:
                return c
            while i < ROW:
                if grid[i][c] == 1 and c+1 < COL and grid[i][c+1] == 1:
                    i+=1
                    c+=1
                elif grid[i][c] == -1 and c-1 >= 0 and grid[i][c-1] == -1:
                    i+=1
                    c-=1
                else:
                    return -1
            return c
                
        ans = []
        for j in range(COL):
            ans.append(helper(0,j,j))
        return ans