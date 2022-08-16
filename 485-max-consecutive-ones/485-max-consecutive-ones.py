class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        mx = 0
        i = 0
        while i < len(nums):
            if nums[i] == 1:
                cur = 0
                while i < len(nums) and nums[i] == 1:
                    i+=1
                    cur +=1
                mx = max(cur, mx)
            i+=1
        if mx == 0 and 1 in nums:
            return 1
        return mx