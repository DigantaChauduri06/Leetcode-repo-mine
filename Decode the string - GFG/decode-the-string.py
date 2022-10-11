#User function Template for python3

class Solution:
    def decodeString_helper(self, s: str) -> str:
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
    def decodedString(self, s):
        # code here
        return self.decodeString_helper(s)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        
        ob = Solution()
        print(ob.decodedString(s))
# } Driver Code Ends