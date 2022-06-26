class Solution:
    def threeSum(self, nums: List[int], tar = 0) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(len(nums)-2):
            # 2 sum
            # rem = tar - nums[i]
            if i >= 1 and nums[i-1] == nums[i]:
                continue
            si, ei = i+1, len(nums)-1
            while si < ei:
                cur = nums[i] + nums[si] + nums[ei]
                if cur == tar:
                    found = [nums[i], nums[si], nums[ei]]
                    res.append(found)
                    while si<ei and nums[si]==nums[si+1]:
                        si+=1
                    while si<ei and nums[ei]==nums[ei-1]:
                        ei-=1
                    si+=1
                    ei-=1
                elif cur > tar:
                    ei -= 1
                else:
                    si += 1
        return res
    
    
# [-1,0,1,2,-1,-4]
# [-4,-1,-1,0,2,4]