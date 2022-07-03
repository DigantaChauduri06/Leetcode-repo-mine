class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = {}
        def helper(i, j):
            if not i in range(m) or not j in range(n):
                return 0
            if i == m - 1 and j == n - 1:
                return 1
            if (i, j) in dp:
                return dp[(i, j)]
            op1 = helper(i+1, j)
            op2 = helper(i, j+1)

            dp[(i, j)] = op1 + op2
            return dp[(i, j)]
        return helper(0,0)