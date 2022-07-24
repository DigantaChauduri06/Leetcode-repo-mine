class Solution:
    def interweavingStrings(self,one, two, three):
    # Write your code here.
        if len(one) + len(two) != len(three):
            return False
        dp = {}
        def helper(i,j,k):
            k = i + j
            if k == len(three):
                return True
            op1,op2 = False,False
            if (i,j) in dp:
                return dp[(i,j)]
            if i < len(one) and one[i] == three[k]:
                op1 = helper(i+1, j, k)
                if op1:
                    dp[(i,j)] = True
                    return True
            if j < len(two) and two[j] == three[k]:
                op2 = helper(i, j+1, k)
                if op2:
                    dp[(i,j)] = True
                    return True
            dp[(i,j)] = op1 or op2
            return op1 or op2
        return helper(0,0,0)
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        return self.interweavingStrings(s1,s2,s3)