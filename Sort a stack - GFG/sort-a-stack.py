from typing import *
class Solution:
    def insertAfter(self, arr: List[int], x: int) -> None:
        if arr and arr[-1] < x:
            arr.append(x)
            return
        if not arr:
            arr.append(x)
            return
        top = arr.pop()
        self.insertAfter(arr, x)
        arr.append(top)
    
    def sorted(self, arr : List[int]) -> None:
        # Code here
        if not arr:
            return
        top = arr.pop()
        self.sorted(arr)
        self.insertAfter(arr, top)



#{ 
 # Driver Code Starts
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ob.sorted(arr)
        for e in range(len(arr)):
            print(arr.pop(), end=" ")
        print()


# } Driver Code Ends