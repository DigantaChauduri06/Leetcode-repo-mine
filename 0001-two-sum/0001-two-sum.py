class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mpp = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in mpp:
                return [i, mpp[diff]]
            mpp[nums[i]] = i
        return [-1,-1]