class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        res = [[1], [1,1]]
        for i in range(3, numRows+1):
            tmp = [1] * i
            # print(tmp)
            for j in range(1, i-1):
                # print(res, j, j-1)
                tmp[j] = res[-1][j-1] + res[-1][j]
            res.append(tmp)
        return res