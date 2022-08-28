class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        track = {}
        ROW,COL = len(mat),len(mat[0])
        for i in range(ROW):
            track[(i,0)] = []
            r,c = i,0
            while r < ROW and c < COL:
                track[(i,0)].append(mat[r][c])
                r+=1
                c+=1
        # print(track)
        for i in range(COL):
            track[(0,i)] = []
            r,c = 0,i
            while r < ROW and c < COL:
                track[(0,i)].append(mat[r][c])
                r+=1
                c+=1
        
        # print(track)
        for key in track:
            track[key].sort()
            r,c = key
            i = 0
            arr = track[key]
            while r < ROW and c < COL:
                mat[r][c] = arr[i]
                i+=1
                r+=1
                c+=1
        return mat
                
        
        
        
        
