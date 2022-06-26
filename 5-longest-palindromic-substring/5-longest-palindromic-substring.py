class Solution:
    def longestPalindrome(self, s: str) -> str:
        maxi = [0, 1]
        def palin(si, ei):
            while si >= 0 and ei < len(s):
                if s[si] != s[ei]:
                    break;
                si -= 1
                ei += 1
            return [si+1, ei]
        
        for i in range(1,len(s)):
            odd = palin(i-1, i+1)
            even = palin(i-1, i)
            cur = max(odd, even, key = lambda x : x[1] - x[0])
            maxi = max(maxi, cur, key = lambda x : x[1] - x[0])
        return s[maxi[0] : maxi[1]]