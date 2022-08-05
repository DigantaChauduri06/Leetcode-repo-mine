class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        i,j = 0,len(matrix[0])-1
        m,n=len(matrix),len(matrix[0])
        while i < m and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] < target:
                i+=1
            else:
                j-=1
        return False