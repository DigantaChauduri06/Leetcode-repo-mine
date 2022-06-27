class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        def helper(idx, track = {}):
            if idx >= len(cost)-2:
                return cost[idx]
            if idx in track:
                return track[idx]
            ans = min(helper(idx+2), helper(idx+1)) + cost[idx]
            track[idx] = ans
            return ans
        
        return min(helper(0), helper(1)) 