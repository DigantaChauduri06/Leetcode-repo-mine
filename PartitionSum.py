
from typing import * 
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total = sum(nums)
        mx = max(nums)
        reqSum = total // k
        if total % k != 0 or reqSum < mx:
            return False
        picked = set()
        def helper(i, cur, k):
            if k == 0:
                return True
            if cur == reqSum:
                return helper(0, 0, k-1)
            if cur > reqSum:
                return False
            if i >= len(nums):
                return False
            if i in picked:
                return helper(i+1, cur, k)
            picked.add(i)
            op1 = helper(i+1, cur + nums[i], k)
            if op1:
                return True
            picked.remove(i)
            op2 = helper(i+1, cur, k)
            if op2:
                return True
            return op1 or op2
        return helper(0, 0, k)
    
    
    
###################
#       O(k*2^n)
####################
####################