class Solution:
    def climbStairs(self, n: int) -> int:
        dp = {}
        def helper(n):
            if n <= 2:
                return n
            if n in dp:
                return dp[n]
            dp[n] =  helper(n-1) + helper(n-2)
            return dp[n]
        return helper(n)