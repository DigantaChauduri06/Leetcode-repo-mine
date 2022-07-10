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
        # res = []
        if len(digits) == 0:
            return []
        def helper(i):
            if i == len(digits) - 1:
                return list(options[digits[i]])
            remaining = helper(i+1)
            chars = options[digits[i]]
            ans = []
            # print(remaining)
            for ch in chars:
                for i in range(len(remaining)):
                    ans.append(ch + remaining[i])
            return ans
        return helper(0)
"""
 d e f d e f d e f
 a a a b b b c c c
"""