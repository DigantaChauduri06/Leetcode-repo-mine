class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        totalSum = sum(nums)
        if totalSum % 2 != 0:
            return False
        currentTarget = totalSum // 2
        dp = [[-1] * (currentTarget + 20)] * len(nums)
        def dfs(i, tsum = currentTarget):
            if i >= len(nums):
                return False if tsum != 0 else True
            if tsum == 0:
                return True
            if tsum < 0:
                return False
            if dp[i][tsum] != -1:
                return dp[i][tsum]
            op1 = dfs(i+1, tsum - nums[i])
            op2 = dfs(i+1, tsum)
            dp[i][tsum] = op1 or op2
            return dp[i][tsum]
        return dfs(0)