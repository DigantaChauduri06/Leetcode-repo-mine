class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if not nums:
            return -1
        cnt = 0
        mej = nums[0]
        for num in nums:
            if num == mej:
                cnt += 1
            else:
                cnt -= 1
            if cnt <= 0:
                mej = num
                cnt = 1
        return mej