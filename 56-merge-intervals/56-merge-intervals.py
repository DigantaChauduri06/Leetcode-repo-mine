class Solution:
    def merge(self, I: List[List[int]]) -> List[List[int]]:
        I.sort(key=lambda x: x[0])
        ans = []
        ans.append([I[0][0], I[0][1]])
        for i in range(1, len(I)):
            if ans[-1][1] >= I[i][0]:
                ans[-1][1] = max(ans[-1][1], I[i][1])
            else:
                ans.append(I[i])
        return ans