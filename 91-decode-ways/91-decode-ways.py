class Solution:
    def numDecodings(self, s: str) -> int:
        @cache
        def helper(i):
            if i == len(s):
                return 1
            op1, op2 = 0, 0
            if (s[i] != '0' and
                i+1 < len(s) and
                int(s[i]+s[i+1]) in range(10,27)):
                op1 = helper(i+2)
            if s[i] != '0':
                op2 = helper(i+1)
            return op1 + op2
        
        return helper(0)