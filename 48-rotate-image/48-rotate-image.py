class Solution:
    def rotate(self, mat: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        #Transepose
        ROW,COL = len(mat),len(mat[0])
        for i in range(ROW):
            for j in range(i+1,COL):
                #swap
                mat[i][j],mat[j][i] = mat[j][i],mat[i][j]
            mat[i] = mat[i][::-1]