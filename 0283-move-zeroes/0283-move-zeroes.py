class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        numOfNonZeros = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i],nums[numOfNonZeros] = nums[numOfNonZeros],nums[i]
                numOfNonZeros+=1