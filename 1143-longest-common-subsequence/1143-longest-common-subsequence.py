class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = {}
        def helper(x=0, y=0):
            # BASE CASE
            if x == len(text1) or y == len(text2):
                return 0
            if (x,y) in dp:
                return dp[(x,y)]
            # only take if charecters are same
            if text1[x] == text2[y]:
                return helper(x+1, y+1) + 1
            # otherwise ignore
            dp[(x,y)] = max(helper(x+1, y), helper(x, y+1))
            return dp[(x,y)]
        
        return helper()
        
"""
abcde
ace

"""