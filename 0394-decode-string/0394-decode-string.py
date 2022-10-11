class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        i = 0
        while i < len(s):
            if s[i] != ']':
                stack.append(s[i])
                i+=1
                continue
            store = ""
            while stack and stack[-1] not in ["1","2","3","4","5","6","7","8","9","0"]:
                ch = stack.pop()
                if ch is not '[':
                    store = ch + store
            number = ""
            while stack and stack[-1] in ["1","2","3","4","5","6","7","8","9","0"]:
                number = stack.pop() + number
            stack.append(int(number) * store)
            
            i+=1
        return "".join(stack)
            
            