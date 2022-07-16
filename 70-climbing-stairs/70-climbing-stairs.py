class Solution:
    def climbStairs(self, n: int) -> int:
        @cache
        def jump(i):
            if i == n-1:
                return 1
            if i == n-2:
                return 2
            one = jump(i+1)
            two = jump(i+2)
            return one + two
        return jump(0)
        
        
        
        
        
        

        
        
        
        
        