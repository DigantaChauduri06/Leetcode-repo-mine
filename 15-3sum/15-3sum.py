class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(len(nums)-2):
            if i >= 1 and nums[i] == nums[i-1]:
                continue
            si, ei = i+1,len(nums)-1
            while si < ei:
                cur = (nums[si]+nums[ei] + nums[i])
                if cur == 0:
                    tmp = [nums[si], nums[ei], nums[i]]
                    f,s = tmp[0],tmp[1]
                    ans.append(tmp)
                    cur = 0
                    while si < ei and f == nums[si]:
                        si+=1
                    while si < ei and s == nums[ei]:
                        ei-=1
                elif cur < 0:
                    si+=1
                else:
                    ei-=1
            while i+1 < len(nums) and nums[i] == nums[i+1]:
                i+=1
        return ans