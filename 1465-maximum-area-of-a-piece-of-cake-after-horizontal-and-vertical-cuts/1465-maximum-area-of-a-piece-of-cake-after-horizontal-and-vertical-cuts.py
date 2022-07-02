class Solution:
    def maxArea(self, h: int, w: int, HC: List[int], VC: List[int]) -> int:
        MOD = int(1e9+7)
        area = 1
        HC.append(0)
        HC.append(h)
        VC.append(0)
        VC.append(w)
        HC.sort()
        VC.sort()
        diff1,diff2 = 0,0
        for i in range(1,len(HC)):
            diff1 = max(diff1, HC[i] - HC[i-1])
        for i in range(1,len(VC)):
            diff2 = max(diff2, VC[i] - VC[i-1])
        return (diff1 * diff2) % MOD
        
        
# [0,1,2,4,5] HC
# [0,1,3,4] VC
