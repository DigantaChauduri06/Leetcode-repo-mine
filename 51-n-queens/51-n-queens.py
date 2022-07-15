class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        board = [["."] * n for _ in range(n)]
        def AllPossible(i):
            if i == n:
                cp = ["".join(board[i]) for i in range(n)]
                res.append(cp)
                return
            for c in range(n):
                if (not inCurrentRow(i,c) and
                    not inNegDiag(i, c) and
                    not inPosDiag(i, c)):
                    board[i][c] = 'Q'
                    AllPossible(i+1)
                    board[i][c] = '.'
            
        def inCurrentRow(r, c):
            for i in range(0, r+1):
                if board[i][c] == 'Q':
                    return True
            return False
        
        def inNegDiag(r, c): # Left portion
            r -= 1
            c -= 1
            while r >= 0 and c >= 0:
                if board[r][c] == 'Q':
                    return True
                r-=1
                c-=1
            return False
        
        def inPosDiag(r, c):
            #(3,0) -> (2,1) -> (1,2)
            r -= 1
            c += 1
            while r >= 0 and c < n:
                if board[r][c] == 'Q':
                    return True
                r -= 1
                c += 1
            return False
        
        AllPossible(0)
        return res
            
            
            
            
            
            
            