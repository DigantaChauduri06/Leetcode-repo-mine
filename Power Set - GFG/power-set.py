#User function Template for python3
class Solution:
    def AllPossibleStrings(self, s):
        # Code here
        temp, res = "", []
        def powerSets(i = 0):
            nonlocal temp
            if i == len(s):
                res.append(temp[:])
                return res
            # Choose
            temp += s[i]
            powerSets(i+1)
            temp = temp[:-1]
            powerSets(i+1)
            return res
        res	= powerSets()
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