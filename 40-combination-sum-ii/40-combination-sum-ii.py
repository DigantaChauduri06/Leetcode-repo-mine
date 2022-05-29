class Solution:
    def combinationSum2(self, cand: List[int], tar: int) -> List[List[int]]:
        j = 0
        res = []
        temp = []
        cand.sort()
        def fun(j, tar):
            if tar == 0:
                res.append(temp.copy())
                return
            elif tar < 0:
                return
            prev = -1
            for i in range(j, len(cand)):
                if prev == cand[i]:
                    continue
                temp.append(cand[i])
                fun(i+1, tar - cand[i])
                temp.pop()
                prev = cand[i]
        fun(0, tar)
        return res
                