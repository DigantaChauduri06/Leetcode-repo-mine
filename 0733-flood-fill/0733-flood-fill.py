class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        visited = set()
        prevColor = image[sr][sc] 
        ROW,COL = len(image), len(image[0])
        def dfs(i,j):
            if (i < 0 
                or j < 0 
                or j >= COL
                or i >= ROW
                or (i,j) in visited
                or image[i][j] != prevColor):
                return
            visited.add((i,j))
            image[i][j]=color
            dfs(i+1,j)
            dfs(i,j+1)
            dfs(i-1,j)
            dfs(i,j-1)
        dfs(sr, sc)
        return image
        