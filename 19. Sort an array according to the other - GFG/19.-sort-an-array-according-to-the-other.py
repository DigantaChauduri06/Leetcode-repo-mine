#User function Template for python3
from collections import defaultdict
class Solution:
    # A1[] : the input array-1
    # N : size of the array A1[]
    # A2[] : the input array-2
    # M : size of the array A2[]
    
    #Function to sort an array according to the other array.
    def relativeSort (self,A1, N, A2, M):
            val_count, ans = defaultdict(int), []
            for item in A1: val_count[item] += 1
            for item in A2:
                if item in val_count:
                    ans.extend([item] * val_count[item])
                    del val_count[item]
            temp = []
            for key in val_count:
                temp.extend([key] * val_count[key])
            temp.sort()
            ans.extend(temp)
            return ans
    

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int (input ())
    while t > 0:
        n, m = list(map(int, input().split()))
        a1 = list(map(int, input().split()))
        a2 = list(map(int, input().split()))
        
        ob=Solution()
        a1 = ob.relativeSort (a1, n, a2, m)
        print (*a1, end = " ")
        
        print ()
        
        t -= 1

# } Driver Code Ends