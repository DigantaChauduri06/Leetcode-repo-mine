#User function template for Python

class Solution:	
    #Function to reverse every sub-array group of size k.
	def reverseInGroups(self, arr, N, k):
		# code here
# 		if N%k != 0:
        i = 0
		while i < N - k:
            # for i in range(i, (i+k // 2)):
            #     arr[i],arr[i+k-1] = arr[i+k-1],arr[i]
            arr[i:i+k] = arr[i:i+k][::-1]
		    i = i+k
# 		print(i)
		arr[i:] = arr[i::][::-1]
        return arr
        
		    


#{ 
 # Driver Code Starts
#Initial template for Python

import math
def main():
    T=int(input())
    while(T>0):
        nk=[int(x) for x in input().strip().split()]
        N=nk[0]
        K=nk[1]
        arr=[int(x) for x in input().strip().split()]
        
        ob = Solution()
        ob.reverseInGroups(arr,N,K)
        for i in arr:
            print(i,end=" ")
        print()
        T-=1

if __name__=="__main__":
    main()




# } Driver Code Ends