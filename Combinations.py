from typing import *

def combinations(n :int,k :int) -> List[List[int]]:
    res, temp = [], []
    # arr = [i+1 for i in range(n)]
    def helper(i):
        if i == (n+1):
            if len(temp) == k:
                res.append(temp[:])
            return
        # pick
        if len(temp) < k:
            temp.append(i)
            helper(i+1)
            temp.pop()
        # non-pick
        helper(i+1)
    
    helper(1)
    return res


print(combinations(4,2))