class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
        n = len(nums)
        k = n - 2
        l = n - 1
        while k >= 0 and nums[k+1] <= nums[k]:
            k-=1
        if k == -1:
            nums.reverse()
            return
        # Find the largest index l > k such that nums[k] < nums[l].
        while l > k and nums[l] <= nums[k]:
            l-=1
        nums[k],nums[l] = nums[l], nums[k]
        l,r = k + 1, len(nums)-1
        while l < r:
            nums[l],nums[r] = nums[r],nums[l]
            l+=1
            r-=1