class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        mej = [-int(1e9),-int(1e9)]
        cnt1,cnt2=0,0
        for n in nums:
            if n == mej[0]:
                cnt1+=1
            elif n == mej[1]:
                cnt2 += 1
            elif cnt1 == 0:
                mej[0] = n
                cnt1 = 1
            elif cnt2 == 0:
                mej[-1] = n
                cnt2 = 1
            else:
                cnt1-=1
                cnt2-=1
        
        # if mej[0] == -1:
        #     return []
        f,s=mej
        c1,c2=0,0
        for n in nums:
            if n == f:
                c1+=1
            if n == s:
                c2+=1
        print(c1,c2)
        if c1 <= len(nums) // 3:
            return [] if c2 <= len(nums) // 3 else [mej[1]]
        if c2 <= len(nums) // 3:
            return [mej[0]]
        return mej if mej[-1] != -1 else [mej[0]]