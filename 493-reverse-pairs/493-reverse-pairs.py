class Solution:
    def merge(self,nums, si, m, ei):
        # Count the inversions
        i, j = si, m+1
        while i <= m and j <= ei:
            if nums[i] > 2 * nums[j]:
                self.count += (m - i + 1)
                j+=1
            else:
                i += 1
        nums[si:ei+1]=sorted(nums[si:ei+1])
    
    def mergeSort(self, nums, si, ei):
        if si >= ei:
            return
        m = (si + ei) // 2
        self.mergeSort(nums, si, m)
        self.mergeSort(nums, m+1, ei)
        self.merge(nums, si, m, ei)
        
    def reversePairs(self, nums: List[int]) -> int:
        self.count = 0
        self.mergeSort(nums,0,len(nums)-1)
        return self.count