class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        for i in range(32):
            lastBit = (n >> i) & 1
            cnt += lastBit
        return cnt