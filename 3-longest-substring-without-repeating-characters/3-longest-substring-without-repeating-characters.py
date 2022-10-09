class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)
        i,j = 0,0
        visited = set()
        mxCnt, cnt = 0,0
        while j < len(s) and i < len(s):
            if not s[j] in visited:
                cnt = (j- i + 1)
                mxCnt = max(mxCnt, cnt)
                visited.add(s[j])
                j+=1
            else:
                visited.remove(s[i])
                i+=1
                cnt = 1
        return mxCnt