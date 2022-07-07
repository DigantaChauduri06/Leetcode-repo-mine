class Solution:
    def permuteUnique(self, nums):
        res = []
        def helper(nums, idx = 0):
            if idx >= len(nums):
                res.append(nums.copy())
            seen = set()
            for i in range(idx, len(nums)):
                if nums[i] in seen:
                    continue
                seen.add(nums[i])
                nums[i], nums[idx] = nums[idx], nums[i]
                helper(nums, idx+1)
                nums[i], nums[idx] = nums[idx], nums[i]
        helper(nums)
        return res