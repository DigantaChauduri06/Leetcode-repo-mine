class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(len(nums)):
            if i != 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1,len(nums)):
                if j - i > 1 and nums[j] == nums[j-1]:
                    continue
                a,b=nums[i],nums[j]
                si,ei=j+1,len(nums)-1
                while si < ei:
                    _sum = nums[si] + nums[ei] + a + b
                    if _sum == target:
                        tmp = [nums[si],nums[ei],a,b]
                        res.append(tmp)
                        while si < ei and tmp[0] == nums[si]:
                            si+=1
                        while si < ei and tmp[1] == nums[ei]:
                            ei-=1
                    elif _sum < target:
                        si+=1
                    else:
                        ei-=1
                while j+1 < len(nums) and nums[j] == nums[j+1]:
                    j+=1
            while i+1 < len(nums) and nums[i] == nums[i+1]:
                i+=1
        return res 
                        
                        
        
        
        