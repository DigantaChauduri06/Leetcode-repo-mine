class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = {}
        def helper(i,j):
            if i== m-1 and j == n-1:
                return 1
            if i < 0 or j < 0 or \
            i >= m or j >= n:
                return 0
            if (i,j) in dp:
                return dp[(i,j)]
            down = helper(i+1, j)
            right = helper(i, j+1)
            dp[(i,j)] = right + down
            return dp[(i,j)]
        return helper(0,0)