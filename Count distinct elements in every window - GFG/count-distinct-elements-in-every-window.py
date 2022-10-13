from collections import *
class Solution:
    def countDistinct(self, A, N, K):
        # Code here
        i,j = 0,0
        vis = defaultdict(lambda : 0)
        ans = []
        while j < N:
            if j - i + 1 <= K:
                vis[A[j]] += 1
                j+=1
            else:
                ans.append(len(vis))
                # print(*vis)
                vis[A[i]] -= 1
                if vis[A[i]] <= 0:
                    del vis[A[i]]
                i+=1
        ans.append(len(vis))
        return ans
                


#{ 
 # Driver Code Starts
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n,k = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        res = Solution().countDistinct(arr, n, k)
        for i in res:
            print (i, end = " ")
        print ()
# } Driver Code Ends