class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for b in s:
            if b in ["(","[","{"]:
                stack.append(b)
            else:
                if not stack:
                    return False
                last = stack[-1]
                if ((b == ')' and last != '(')
                   or (b == ']' and last != '[')
                   or (b == '}' and last != '{')):
                    return False
                stack.pop()
        return True if not stack else False