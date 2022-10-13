#User function Template for python3

class Solution:
    def lenOfLongSubarr (self, arr, n, k) : 
        #Complete the function
        sm = 0
        mpp = {}
        mxlen = 0
        for i, num in enumerate(arr):
            sm += num
            # print(sm, mpp)
            if sm == k:
                # print(sm)
                mxlen = max(mxlen, i+1)
            if (sm - k) in mpp:
                # print(i, mpp[sm-k])
                mxlen = max(mxlen, (i - mpp[sm-k]))
            if (sm) not in mpp:
                mpp[sm] = i
        return mxlen if sm != 0 else n
    



#{ 
 # Driver Code Starts
#Initial Template for Python 3


for _ in range(0,int(input())):
    
    n, k = map(int , input().split())
    arr = list(map(int,input().strip().split()))
    ob = Solution()
    print(ob.lenOfLongSubarr(arr, n, k))




# } Driver Code Ends