class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        si, ei = 0, len(nums)-1
        while si < ei:
            cur_sum = nums[si] + nums[ei]
            if cur_sum == target:
                return [si+1, ei+1]
            elif cur_sum > target:
                ei -= 1
            else:
                si += 1
        return [-1,-1]
            
            
            
            
            
            
            
            
# [2,7,11,15]