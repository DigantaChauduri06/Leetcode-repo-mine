class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        tmp,res = [],[]
        nums.sort()
        def helper(i):
            if i >= len(nums):
                res.append(tmp[:])
                return
            tmp.append(nums[i])
            helper(i+1)
            tmp.pop()
            while i+1 < len(nums) and nums[i+1] == nums[i]:
                i+=1
            helper(i+1)
        helper(0)
        return res