class Solution:
    def numberOfWeakCharacters(self, p: List[List[int]]) -> int:
        p.sort(key = lambda x: (-x[0], x[1]))
        cnt = 0
        maxD = -1e9
        for _,dif in p:
            if dif < maxD:
                cnt += 1
            else:
                maxD = dif
        return cnt