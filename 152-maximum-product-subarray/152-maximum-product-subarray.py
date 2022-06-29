class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # store current max and current min
        curMin,curMax,res = 1,1,max(nums)
        for num in nums:
            if num == 0:
                curMin,curMax = 1,1
                continue
            temp = num * curMax
            curMax = max(num, num * curMax, num * curMin)
            curMin = min(num, temp, num * curMin)
            res = max(res, curMax)
        return res
        