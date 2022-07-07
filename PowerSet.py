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
            return res

def AllPossibleStrings(s):
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
    return res

s = Solution()

print(AllPossibleStrings("abc"))

["","a","ab","abc","b","bc","c"]