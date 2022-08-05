class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt = 0
        mej = nums[0]
        for i in range(len(nums)):
            if cnt == 0:
                mej = nums[i]
                cnt += 1
            elif nums[i] == mej:
                cnt += 1
            else:
                cnt -= 1
        return mej