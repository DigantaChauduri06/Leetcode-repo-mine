class Solution:
    def combinationSum(self, cand: List[int], target: int) -> List[List[int]]:
        res,tmp = [],[]
        def helper(i, cur):
            if i >= len(cand):
                if cur == target:
                    res.append(tmp[:])
                return
            if cur == target:
                res.append(tmp[:])
                return
            if cur+cand[i] <= target:
                tmp.append(cand[i])
                cur += cand[i]
                helper(i, cur)
                cur -= cand[i]
                tmp.pop()
            helper(i+1, cur)
        helper(0,0)
        return res
            