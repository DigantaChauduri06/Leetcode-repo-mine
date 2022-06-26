class Solution:
    def maxArea(self, height: List[int]) -> int:
        si, ei = 0, len(height) -1
        mxLen = 0
        while (si < ei):
            cur = (ei - si) * min(height[si], height[ei])
            mxLen = max(mxLen, cur)
            if height[si] > height[ei]:
                ei-=1
            else:
                si+=1
        return mxLen
