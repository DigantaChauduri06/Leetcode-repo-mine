#User function Template for python3


class Solution:
    
    #Function to find all elements in array that appear more than n/k times.
    def countOccurence(self,arr,n,k):
           #Your code here
           count = 0
           dic={}
           for i in arr:
               if i not in dic:
                   dic[i]=1
               else:
                   dic[i]+=1
           for i in dic.values():
               if i > n//k:
                   count+=1
           return count

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math



def main():
        T=int(input())
        while(T>0):
            
            N=int(input())

            A=list(map(int,input().split()))
            
            K=int(input())
            
            print(Solution().countOccurence(A, N, K))
            
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends