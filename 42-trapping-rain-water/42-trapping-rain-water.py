class Solution:
    def trap(self, height: List[int]) -> int:
        lmax,rmax = [],[]
        lmax.append(height[0])
        rmax.append(height[-1])
        for i in range(1,len(height)):
            lmax.append(max(height[i], lmax[-1]))
        
        for i in range(len(height)-2, -1,-1):
            rmax.append(max(height[i], rmax[-1]))
        
        rmax.reverse()
        
        diff = 0
        
        for i in range(len(height)):
            diff += min(abs(height[i] - lmax[i]), abs(height[i] - rmax[i]))
        
        return diff