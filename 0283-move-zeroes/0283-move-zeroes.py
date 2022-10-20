class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        numOfZeros = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i],nums[numOfZeros] = nums[numOfZeros],nums[i]
                numOfZeros+=1