class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ROW, COL = len(board), len(board[0])
        dx = [0,0,-1,1]
        dy = [-1,1,0,0]
        def helper(r, c, i):
            if i == len(word):
                return True
            if (r < 0 or
               c < 0 or
               r >= ROW or
               c >= COL or
               word[i] != board[r][c]):
                return False
            tmp = board[r][c]
            board[r][c] = '#'
            for x in range(4):
                if helper(r+dx[x], c+dy[x], i+1):
                    return True 
            board[r][c] = tmp
            return False
        
        for i in range(ROW):
            for j in range(COL):
                if board[i][j] == word[0]:
                    if helper(i,j,0):
                        return True
        return False