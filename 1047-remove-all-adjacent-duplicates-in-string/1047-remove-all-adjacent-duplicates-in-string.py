class Solution:
    def removeDuplicates(self, s: str) -> str:
        if len(s) <= 1:
            return s
        stack = []
        i = 0
        while i < len(s):
            if not stack:
                stack.append(s[i])
                i+=1
                continue
            if stack and stack[-1] == s[i]:
                stack.pop()
                i+=1
                continue
            stack.append(s[i])
            i+=1
        # print()
        return ''.join(stack) if stack else ""
            
            
            
# [a,]