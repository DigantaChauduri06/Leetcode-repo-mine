#User function Template for python3
from collections import *
class Solution:
    #Function to check if two arrays are equal or not.
    def check(self,A,B,N):
        mpp1 = defaultdict(int)
        for n in A:
            mpp1[n]+=1
        for n in B:
            if n not in mpp1:
                return False
            mpp1[n] -= 1
        for key in mpp1:
            if mpp1[key] != 0:
                return False
        return True
            
        #return: True or False
        
        #code here


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for tc in range(t):
        
        N=int(input())
        
        A = [int(x) for x in input().replace('  ',' ').strip().split(' ')]
        B = [int(x) for x in input().replace('  ',' ').strip().split(' ')]
        ob=Solution()
        if ob.check(A,B,N):
            print(1)
        else:
            print(0)
        
                
                
# } Driver Code Ends