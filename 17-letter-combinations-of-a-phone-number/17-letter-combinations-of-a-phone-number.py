options = {
    "2": "abc",
    "3": "def",
    "4": "ghi",
    "5": "jkl",
    "6": "mno",
    "7": "pqrs",
    "8": "tuv",
    "9": "wxyz"
}
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res, tmp = [], []
        if len(digits) == 0:
            return []
        def helper(i):
            if i == len(digits):
                s = ''.join(tmp.copy())
                res.append(s)
                return
            cur = options[digits[i]]
            for j in range(len(cur)):
                tmp.append(cur[j])
                helper(i+1)
                tmp.pop()
            
        helper(0)
        return res
"""
 d e f d e f d e f
 a a a b b b c c c
"""