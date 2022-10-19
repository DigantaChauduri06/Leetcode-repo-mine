class Solution:
    def titleToNumber(self, C: str) -> int:
        res = 0
        for c in C:
            res = res * 26 + ord(c) - ord('A') + 1
        return res