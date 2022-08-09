class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if nums[abs(nums[i])-1] < 0:
                return abs(nums[i])
            nums[abs(nums[i])-1] *= -1
        # print(nums)
        return -1