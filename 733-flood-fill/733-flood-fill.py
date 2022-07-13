class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        startingColor = image[sr][sc]
        ROW,COL = len(image), len(image[0])
        dx = [0,0,-1,1]
        dy = [-1,1,0,0]
        def helper(r, c):
            if (r < 0 or
                c < 0 or
                r >= ROW or
                c >= COL or
               image[r][c] != startingColor):
                return
            image[r][c] = 'X'
            for i in range(4):
                helper(r+dx[i], c+dy[i])
        
        helper(sr, sc)
        for i in range(ROW):
            for j in range(COL):
                if image[i][j] == 'X':
                    image[i][j] = color
        return image
            