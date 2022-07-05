class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        track = set()
        
        for n in nums:
            track.add(n)
        
        mxLen = 1
        cur = 1
        for n in nums:
            if n-1 in track:
                continue
            tmp = n+1
            while tmp in track:
                tmp+=1
                cur+=1
            mxLen = max(mxLen, cur)
            cur = 1
        return mxLen