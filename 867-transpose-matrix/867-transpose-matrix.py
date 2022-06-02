class Solution:
    def transpose(self, mat: List[List[int]]) -> List[List[int]]:
        m,n = len(mat),len(mat[0])
        res = []
        for i in range(n):
            temp = []
            for j in range(m):
                temp.append(mat[j][i])
            res.append(temp)
        return res;