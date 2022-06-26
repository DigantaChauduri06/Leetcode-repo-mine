class Solution:
    def threeSum(self, nums: List[int], tar = 0) -> List[List[int]]:
        temp = set()
        # res = []
        for i in range(len(nums)):
            track = {}
            # 2 sum
            for j in range(i+1, len(nums)):
                cur = nums[i] + nums[j]
                diff = tar - cur
                if track.get(diff, "None") != "None":
                    # print([nums[i], nums[j], nums[track[diff]]])
                    found = sorted([nums[i], nums[j], nums[track[diff]]])
                    temp.add(tuple(found))
                else:
                    track[nums[j]] = j
        return list(temp)
        
# [-1,0,1,2,-1,-4]