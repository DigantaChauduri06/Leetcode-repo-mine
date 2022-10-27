class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if not nums:
            return False
        if len(nums) == 1:
            return nums[-1] == target
        low, high = 0, len(nums)-1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                return True
            if nums[mid] == nums[high]:
                if nums[high] == target:
                    return True
                high -= 1
            # 3 4 5 6 1 2
            elif nums[mid] > nums[high]:
                if nums[low] <= target and nums[mid] > target:
                    high = mid - 1
                else:
                    low = mid + 1
                    
            elif nums[mid] < nums[high]:
                if target <= nums[high] and nums[mid] <= target:
                    low = mid + 1
                else:
                    high = mid - 1
                
        return False