class Solution:
    def setZeroes(self, mat: List[List[int]]) -> None:
        rowZero = mat[0][0] == 0
        self.ROW,self.COL = len(mat),len(mat[0])
        for i in range(self.ROW):
            for j in range(self.COL):
                if mat[i][j] == 0:
                    mat[0][j] = 0
                    if i > 0:
                        mat[i][0] = 0
                    else:
                        rowZero = True
        for i in range(1,self.ROW):
            for j in range(1,self.COL):
                if mat[0][j] == 0 or mat[i][0] == 0:
                    mat[i][j] = 0
        if mat[0][0] == 0:
            for r in range(self.ROW):
                mat[r][0] = 0
        if rowZero:
            for c in range(self.COL):
                mat[0][c] = 0
            
        