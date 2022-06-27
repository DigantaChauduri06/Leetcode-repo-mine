class Solution:
    def climbStairs(self, n: int, track = {}) -> int:
        if n <= 2: 
            return n
        prev1,prev2 = 1,2
        for i in range(2, n):
            cur = prev1 + prev2
            prev1 = prev2
            prev2 = cur
            
        return prev2
        
        
        
        
        
        
        
# if n <= 2:
#     return n
# if n in track:
#     return track[n]
# ans = self.climbStairs(n-1)+self.climbStairs(n-2)
# track[n] = ans
# return ans
        
        
        
        
        