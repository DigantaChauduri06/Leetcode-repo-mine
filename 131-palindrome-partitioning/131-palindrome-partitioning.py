class Solution:
    def partition(self, s: str):
        tmp, res = [],[]
        def isPalin(i, j):
            while i < j:
                if s[i] != s[j]:
                    return False
                i+=1
                j-=1
            return True
        def helper(start):
            if start >= len(s):
                res.append(tmp[:])
                return
            for i in range(start,len(s)):
                if isPalin(start, i):
                    tmp.append(s[start:i+1])
                    helper(i+1)
                    tmp.pop()
        helper(0)
        return res
                
        
"""
ab

a b
a b

"""