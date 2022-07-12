class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        s = []
        res = []
        def helper(op, cl):
            if op == cl == n:
                res.append(''.join(s))
                return
            if op <= n:
                s.append('(')
                helper(op+1, cl)
                s.pop()
            if op > cl:
                s.append(')')
                helper(op, cl+1)
                s.pop()
        helper(0,0)
        return res
            
            