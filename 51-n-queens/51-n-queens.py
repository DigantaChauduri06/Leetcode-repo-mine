class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        colSet, posDig, negDig = set(), set(),set()
        board = [["."]*n for _ in range(n)]
        ans = []
        def backtrack(r):
            if r == n:
                copy = ["".join(row) for row in board]
                ans.append(copy)
                return
            for c in range(n):
                if (c in colSet or
                   (r+c) in posDig or
                   (r-c) in negDig):
                    continue
                
                board[r][c] = 'Q'
                colSet.add(c)
                posDig.add(r+c)
                negDig.add(r-c)
                backtrack(r+1)
                board[r][c] = '.'
                colSet.remove(c)
                posDig.remove(r+c)
                negDig.remove(r-c)
        backtrack(0)
        return ans