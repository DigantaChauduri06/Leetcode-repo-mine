class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mxCnt = 0
        for i in range(len(s)):
            visited = set()
            cnt = 0
            for j in range(i, len(s)):
                if not s[j] in visited:
                    cnt += 1
                else:
                    break
                visited.add(s[j])
            mxCnt = max(mxCnt, cnt)
        return mxCnt