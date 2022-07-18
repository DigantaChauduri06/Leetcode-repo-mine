class Solution:
    def splitString(self, s: str) -> bool:
        tmp = []
        # res = []
        def isValid(tmp):
            for i in range(1, len(tmp)):
                if tmp[i]  != tmp[i-1] - 1: # 2 != 1 -1
                    return False
            return True
        def helper(i):
            #! BASE CASE
            if i >= len(s):
                if isValid(tmp):
                    # print(tmp)
                    return True
                return False
            for j in range(1, len(s)):
                if len(tmp) >= 2:
                    if tmp[-1] + 1 != tmp[-2]:
                        return False
                    
                tmp.append(int(s[i: i+j]))
                if helper(i+j):
                    return True
                tmp.pop()
            return False        

        return helper(0)
            