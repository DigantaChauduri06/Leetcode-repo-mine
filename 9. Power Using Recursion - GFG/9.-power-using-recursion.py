#User function Template for python3

class Solution:
    def RecursivePower(self,n,p):
        '''
        return value of n^p recursively;
        '''
        # code here
        if p == 0:
            return 1
        
        return n * self.RecursivePower(n, p-1)

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n,p = map(int,input().strip().split())
        print(Solution().RecursivePower(n,p))
# } Driver Code Ends