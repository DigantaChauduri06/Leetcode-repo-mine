class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def modify(pos):
            if pos >= 81:
                return True
            i = pos // 9
            j = pos % 9
            if board[i][j] != '.':
                return modify(pos+1)
            for c in range(1,10):
                ch = str(c)
                if (not isInRow(ch, i, j) and
                    not isInCol(ch, i, j) and
                    not isIn3X3(ch, i, j)):
                    
                    board[i][j] = ch
                    if modify(pos+1):
                        return True
                    board[i][j] = '.'
            return False
        
        
        def isInRow(ch, r, c):
            for i in range(9):
                if board[i][c] == ch:
                    return True
            return False
        
        def isInCol(ch, r, c):
            for i in range(9):
                if board[r][i] == ch:
                    return True
            return False
            
            
        def isIn3X3(ch, r, c):
            track = {
                (0,0): (0,0),
                (0,1): (0,3),
                (0,2): (0,6),
                (1,0): (3,0),
                (1,1): (3,3),
                (1,2): (3,6),
                (2,0): (6,0),
                (2,1): (6,3),
                (2,2): (6,6)
            }
            row,col = track[(r//3,c//3)]
            for i in range(row,row+3):
                for j in range(col,col+3):
                    if board[i][j] == ch:
                        return True
            return False
        
        modify(0)
        return board
        
        
        
        
        
        
        
        
        
        
        
        
        