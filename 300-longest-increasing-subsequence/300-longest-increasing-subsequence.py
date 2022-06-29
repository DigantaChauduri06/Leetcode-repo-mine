class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1] * len(nums)
        dp[len(nums)-1] = 1
        for i in range(len(nums)-2, -1, -1):
            # isSmallestToRight = True
            x, cur = len(nums)+1, int(1e9)
            for j in range(i+1, len(nums)):
                if nums[i] < nums[j]:
                    dp[i] = max(dp[i], 1 + dp[j])
                
            
        # print(dp)
        return max(dp)
        
# [10,9,2,5,3,7,101,18]
# [0,1,0,3,2,3]

"""
  [2,2,4,3,3,2,1,1]
  [3,1,2,1]

"""

"""
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = {}
        @lru_cache(None)
        def helper(i, cur = sys.maxsize):
            if i < 0:
                return 0
            op1 = 0
            if (i, cur) in dp:
                return dp[(i, cur)]
            # we can pick if current value is lesser than
            if cur > nums[i]:
                op1 = 1 + helper(i-1, nums[i])
            op2 = helper(i-1, cur)
            dp[(i, cur)] = max(op1, op2)
            return dp[(i, cur)]
        
        return helper(len(nums)-1)
"""