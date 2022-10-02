class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        lps = [0 for _ in range(len(needle))]
        i,prevLPS = 1, 0
        while i < len(needle):
            if needle[i] == needle[prevLPS]:
                lps[i] = prevLPS + 1
                i+=1
                prevLPS+=1
            else:
                if prevLPS == 0:
                    lps[i] = 0
                    i+=1
                else:
                    prevLPS = lps[prevLPS - 1]
                    
        i,j = 0, 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i,j = i+1,j+1
            else:
                if j == 0:
                    i+=1
                else:
                    j = lps[j-1]
            if j == len(needle):
                return i - len(needle)
        return -1