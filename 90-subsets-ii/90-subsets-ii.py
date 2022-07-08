class Solution:
    def subsetsWithDup(self, nums):
        res, temp = [],[]
        nums.sort()
        def helper(i):
            if i == len(nums):
                res.append(temp[:])
                return
            temp.append(nums[i])
            helper(i+1)
            temp.pop()
            while i+1 < len(nums) and nums[i] == nums[i+1]:
                i+=1
            helper(i+1)
            return
        helper(0)
        return res
        