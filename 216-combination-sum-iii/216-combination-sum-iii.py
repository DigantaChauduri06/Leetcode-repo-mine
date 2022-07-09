class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
            res, temp = [],[]
            # candidates = [((i%9)+1) for i in range(n)]
            candidates = [i+1 for i in range(9 if n >= 9 else n)]
            # print(candidates)
            # candidates.sort()
            def helper(i, tar):
                if i == len(candidates):
                    if tar == 0 and len(temp) == k:
                        res.append(temp[:])
                    return
                if len(temp) > k:
                    return
                ele_need = k - len(temp)
                ele_left = n - i + 1
                if ele_need > ele_left:
                    return
                if tar-candidates[i] >= 0:
                    tar = tar-candidates[i]
                    temp.append(candidates[i])
                    while i+1 < len(candidates) and candidates[i] == candidates[i+1]:
                        i+=1    
                    helper(i+1, tar)
                    temp.pop()
                    tar = tar+candidates[i]
                while i+1 < len(candidates) and candidates[i] == candidates[i+1]:
                    i+=1
                helper(i+1, tar)
            helper(0, n)
            return res