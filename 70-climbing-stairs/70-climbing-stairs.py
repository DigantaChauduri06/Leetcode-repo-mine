track = {}
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        if n in track:
            return track[n]
        ans = self.climbStairs(n-1)+self.climbStairs(n-2)
        track[n] = ans
        return ans