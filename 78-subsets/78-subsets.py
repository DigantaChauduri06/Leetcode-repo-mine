class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res, tmp = [], []
        def helper(i):
            if i >= len(nums):
                res.append(tmp[:])
                return
            tmp.append(nums[i])
            helper(i+1)
            tmp.pop()
            helper(i+1)
        helper(0)
        return res