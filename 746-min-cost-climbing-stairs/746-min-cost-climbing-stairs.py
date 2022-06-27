class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        if len(cost) <= 2:
            return cost[0] if len(cost) == 1 else min(cost[0], cost[1])
        n = len(cost)
        dp = [0] * (n+1)
        dp[0],dp[1] = cost[0],cost[1]
        
        for i in range(2, n):
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
    
        return min(dp[n-1], dp[n-2])
    
    
    
    
    
    
    
    
#      def helper(idx, track = {}):
#             if idx >= len(cost)-2:
#                 return cost[idx]
#             if idx in track:
#                 return track[idx]
#             ans = min(helper(idx+2), helper(idx+1)) + cost[idx]
#             track[idx] = ans
#             return ans
        
#         return min(helper(0), helper(1)) 