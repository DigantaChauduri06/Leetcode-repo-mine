class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        if num == 0:
            return True
        n = num // 2
        while n < num:
            a = int(str(n)[::-1])
            if a + n == num:
                return True
            n+=1
        return False
            