#User function Template for python3
class Solution:
    
    #Function to delete middle element of a stack.
    i = 0
    def deleteMid(self, s, sizeOfStack):
        if not s:
            return
        md = sizeOfStack // 2
        top = s.pop()
        Solution.i+=1
        self.deleteMid(s,sizeOfStack)
        Solution.i -= 1
        if md != Solution.i:
            s.append(top)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():
    t=int(input())
    while(t>0):
        sizeOfStack=int(input())
        myStack=[int(x) for x in input().strip().split()]
        ob = Solution()
        ob.deleteMid(myStack,sizeOfStack)
        while(len(myStack)>0):
            print(myStack[-1],end=" ")
            myStack.pop()
        print()
        t-=1


if __name__=="__main__":
    main()
    
    
# } Driver Code Ends