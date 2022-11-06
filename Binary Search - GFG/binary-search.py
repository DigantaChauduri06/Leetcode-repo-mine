#User function template for Python

class Solution:	
	def binarysearch(self, arr, n, k):
		# code here
		def helper(arr = arr, low = 0, high = len(arr)-1):
		    if low > high:
		        return -1
		    m = low + (high - low) // 2
		    if k == arr[m]:
		        return m
		    if k < arr[m]:
		        return helper(arr, low, m-1)
		    else:
		        return helper(arr, m+1, high)
        return helper()


#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t=int(input())
    for i in range(t):
        n=int(input())
        arr=list(map(int, input().strip().split(' ')))
        k=int(input())
        ob = Solution()
        print (ob.binarysearch(arr, n, k))


# } Driver Code Ends