class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(len(haystack)-len(needle)+1):
            if haystack[i] == needle[0]:
                isFound = True
                j = i
                k = 0
                while k < len(needle) and j < len(haystack):
                    if needle[k] != haystack[j]:
                        isFound = False
                        break
                    k+=1
                    j+=1
                if isFound:
                    return i
        return -1