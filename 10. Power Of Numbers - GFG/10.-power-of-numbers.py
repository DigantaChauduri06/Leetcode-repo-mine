#User function Template for python3
MOD = int(1e9+7)

class Solution:
    #Complete this function
    def power(self,N,R):
        #Your code here
        if R == 0:
          return 1
        if R == 1:
            return N
        smaller1, smaller2 = 1,1
        if R & 1:
            smaller1 = (N * self.power(N, R - 1)) % MOD
        else:
            smaller2 = (self.power(N, R // 2) ** 2) % MOD
        
        return (smaller1 * smaller2) % MOD
    

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math

def main():
    
    T=int(input())
    
    while(T>0):
        
        N=input()
        R=N[::-1]
        
        ob=Solution();
        ans=ob.power(int(N),int(R))
        print(ans)
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends