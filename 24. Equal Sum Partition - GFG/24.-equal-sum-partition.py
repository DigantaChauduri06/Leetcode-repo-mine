#User function Template for python3

class Solution:
    
    def findPartition(self, arr, n):
        summ = sum(arr)
        
        if summ%2==1:
            return False
            
        lookup = [[False for _ in range(summ // 2 + 1)] for _ in range(n + 1)]
        
        
        # when the summ is zero, we can partitition the data
        for i in range(n + 1):
            lookup[i][0] = True

        # when there is no element is array
        for j in range(1, summ // 2 + 1):
            lookup[0][j] = False 

        for i in range(1, n + 1):
            for j in range(1, summ // 2 + 1):
                
                if j < arr[i - 1]:
                    lookup[i][j] = lookup[i - 1][j]
                else:
                    lookup[i][j] = lookup[i - 1][j] or lookup[i - 1][j - arr[i - 1]]

        return lookup[-1][-1]

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        n=int(input())
        
        arr=[int(x) for x in input().strip().split()]
        ob=Solution()
        if ob.findPartition(arr,n):
            print('YES')
        else:
            print('NO')
        
                
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
                
# } Driver Code Ends