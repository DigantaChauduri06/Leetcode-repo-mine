class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m,n = len(text1), len(text2)
        dp=[[0]*(n+1) for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                if text1[i-1] == text2[j-1]:
                    dp[i][j] = dp[i-1][j-1]+1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[-1][-1]
        
        
        
"""
abcde
ace

        def helper(x=0, y=0):
            # BASE CASE
            if x == len(text1) or y == len(text2):
                return 0
            if (x,y) in dp:
                return dp[(x,y)]
            # only take if charecters are same
            if text1[x] == text2[y]:
                dp[(x,y)] = helper(x+1, y+1) + 1
                return dp[(x,y)]
            # otherwise ignore
            dp[(x,y)] = max(helper(x+1, y), helper(x, y+1))
            return dp[(x,y)]

"""