class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [-1 for _ in range((target+1))]
        def helper(cur):
            if cur == target:
                return 1
            op1= 0
            if dp[cur] != -1:
                return dp[cur]
            dp[cur] = 0
            for num in nums:
                if num + cur <= target:
                    dp[cur] += helper(cur + num)
            return dp[cur]
        return helper(0)
        
        