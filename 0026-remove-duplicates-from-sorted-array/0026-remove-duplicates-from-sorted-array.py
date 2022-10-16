class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) <= 0:
            return len(nums)
        j = 1
        i = 1
        while i < len(nums):
            if nums[i] != nums[i-1]:
                ele = nums[i]
                k = i
                while k < len(nums) and nums[k] == ele:
                    k+=1
                nums[j],nums[i] = nums[i],nums[j]
                j+=1
                i = k
            else:
                i+=1
        return j