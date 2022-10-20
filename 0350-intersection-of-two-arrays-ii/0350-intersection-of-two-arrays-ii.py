class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mpp1,mpp2 = defaultdict(lambda : 0),defaultdict(lambda : 0)
        ans = []
        for num in nums1:
            mpp1[num]+=1
        for num in nums2:
            mpp2[num]+=1
        
        for key in mpp1:
            if key in mpp2:
                a,b = mpp1[key],mpp2[key]
                if a > b:
                    ans = ans + [key] * b
                else:
                    ans = ans + [key] * a
        return ans
        