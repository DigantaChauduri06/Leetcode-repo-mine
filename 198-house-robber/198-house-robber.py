class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return nums[0] if len(nums) == 1 else max(nums[1], nums[0])
        # [rob1, rob2, ele1, ele2...]
        rob1, rob2 = 0,0
        for ele in nums:
            cur = max(rob1 + ele, rob2)
            rob1 = rob2
            rob2 = cur
        return rob2