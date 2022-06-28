class Solution:
    def numDecodings(self, s: str) -> int:
        dp = [-1] * (len(s)+1)
        @cache
        def numberOfWays(s):
            if len(s) == 0:
                return 1
            if len(s) == 1:
                return 1 if len(s) == 1 and s[0] != '0' else 0
            if dp[len(s)] is not -1:
                return dp[len(s)]
            # take single char
            op1,op2 = 0,0
            c = s[0:1]
            if int(c) in range(1,10):
                op1 = numberOfWays(s[1:])
            #Take 2 chars
            c = s[0:2]
            if int(c) in range(10, 27):
                op2 = numberOfWays(s[2:])
            dp[len(s)] = op1 + op2
            return dp[len(s)]
        return numberOfWays(s)