from queue import Queue
direc = [[1,2],[1,-2],[-1,2],[-1,-2],[2,1],[2,-1],[-2,1],[-2,-1]]

class Solution:
    def check(self,i,j,n,vis):
        return i >= 0 and j >= 0 and i < n and j < n and vis[i][j] == 0

	def minStepToReachTarget(self, KPos, TargetPos, n):
	    KPos[0] = KPos[0]-1; KPos[1] = KPos[1]-1
	    TargetPos[0] = TargetPos[0]-1; TargetPos[1] = TargetPos[1]-1
	    
	    if KPos == TargetPos:
	        return 0
	    q = Queue()
	    q.put([KPos[0],KPos[1],0])
	    
	    vis = [[0 for _ in range(n)] for _ in range(n)]
	    vis[KPos[0]][KPos[1]] = 1
	    
	    while not q.empty():
	        x,y,d = q.get()
            if x == TargetPos[0] and y == TargetPos[1]:
                return d
	        for u,v in direc:
	            p = x + u
	            r = y + v
	            if self.check(p,r,n,vis):
	                q.put([p,r,d+1])
	                vis[p][r] = 1
	                
	    return -1   

#{ 
#  Driver Code Starts
if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		N = int(input())
		KnightPos = list(map(int, input().split()))
		TargetPos = list(map(int, input().split()))
		obj = Solution()
		ans = obj.minStepToReachTarget(KnightPos, TargetPos, N)
		print(ans)

# } Driver Code Ends