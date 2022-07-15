class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res,tmp  = [],[]
        def helper(i):
            if i == n+1:
                if len(tmp) == k:
                    res.append(tmp[:])
                return
            if len(tmp) == k:
                res.append(tmp[:])
                return
            if n - i + 1 < k - len(tmp):
                return
            tmp.append(i)
            helper(i+1)
            tmp.pop()
            helper(i+1)
        
        helper(1)
        return res
            