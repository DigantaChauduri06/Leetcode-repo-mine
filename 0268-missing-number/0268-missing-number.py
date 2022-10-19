class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        xor = 0
        for num in nums:
            xor = xor ^ num
        for i in range(len(nums)+1):
            xor = xor ^ i
        return xor