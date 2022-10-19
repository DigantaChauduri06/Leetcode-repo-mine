class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            lastBit = (n >> i) & 1
            res = res | (lastBit << (31 - i))
        return res