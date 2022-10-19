class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = []
        for i in range(numRows+1):
            tmp = [1] * i
            for j in range(1, i-1):
                tmp[j] = ans[i-1][j-1] + ans[i-1][j]
            # if tmp:
            ans.append(tmp)
        ans.pop(0)
        return ans
            