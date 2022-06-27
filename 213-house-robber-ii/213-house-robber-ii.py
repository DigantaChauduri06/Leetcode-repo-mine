class Solution:
    def rob(self, nums: List[int]) -> int:
        def HouseRobber1(si, ei):
            #[rob1, rob2, ele1, ele2]
            if len(nums) <= 2:
                return max(nums[0], nums[1]) if len(nums) == 2 else nums[0]
            rob1,rob2 = 0, 0
            for i in range(si, ei+1):
                cur = max(nums[i]+ rob1, rob2)
                rob1 = rob2
                rob2 = cur
            return rob2
        return max(HouseRobber1(0, len(nums)-2), HouseRobber1(1, len(nums)-1))