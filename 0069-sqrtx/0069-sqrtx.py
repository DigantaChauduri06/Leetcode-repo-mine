class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1:
            return x
        low,high = 0,x // 2 + 1
        while low <= high:
            m = (low + high) // 2
            if m*m == x:
                return m
            if m*m > x:
                high = m-1
            else:
                low = m+1
        return low-1