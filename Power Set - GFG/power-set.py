#User function Template for python3
class Solution:
	def AllPossibleStrings(self, s):
		# Code here
            def powerSets(s):
                if len(s) == 0:
                    return [""]
                smallerProblem = powerSets(s[1:])
                ans = []
                for st in smallerProblem:
                    ans.append(st)
                for i in range(len(ans)):
                    ans.append(s[0] + ans[i])
                return ans
            res	= powerSets(s)
            res.sort()
            res.pop(0)
            return res

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		s = input()
		ob = Solution();
		ans = ob.AllPossibleStrings(s)
		for i in ans:
			print(i, end = " ");
		print()
# } Driver Code Ends