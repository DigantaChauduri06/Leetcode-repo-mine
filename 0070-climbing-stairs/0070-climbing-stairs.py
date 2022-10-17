class Solution:
    def climbStairs(self, n: int) -> int:
        dp = {}
        def helper(i):
            if i <= 2:
                return i
            if i in dp:
                return dp[i]
            dp[i] = helper(i-1) + helper(i-2)
            return dp[i]
        return helper(n)