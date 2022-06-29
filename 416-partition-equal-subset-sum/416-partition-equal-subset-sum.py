class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        #find the sum of the array
        checkSum = sum(nums)
        
        #if the sum is odd, we can't partition it into two sets
        if checkSum%2 != 0:
            return False
        
        #run a cansum for the array
        memo = {}
        return self.canSum(nums, checkSum/2, memo)
    
    
    
    def canSum(self, nums, req, memo):
        #return memoized value if present
        if req in memo:
            return memo[req]
        #if required value < 0, return False
        if req < 0:
            return False
        #if required value = 0, return True
        if req == 0:
            return True
        
        for index, num in enumerate(nums):
            #calculate the remainder
            remainder = req - num
            
            #check for this remainder in the remaining array
            arr = [*nums[:index], *nums[index+1:]]
            if self.canSum(arr, remainder, memo) == True:
                memo[req] = True
                return True
        memo[req] = False
        return False
