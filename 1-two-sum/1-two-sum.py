class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        track = {}
        for i in range(0, len(nums)):
            rem = target - nums[i]
            if rem in track:
                return [track[rem], i]
            track[nums[i]] = i
        return [-1,-1]