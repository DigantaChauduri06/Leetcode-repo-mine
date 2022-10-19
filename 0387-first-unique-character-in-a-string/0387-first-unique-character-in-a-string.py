class Solution:
    def firstUniqChar(self, s: str) -> int:
        mpp = defaultdict(lambda: 0)
        mpp2 = defaultdict(lambda: 0)
        for i in range(len(s)):
            mpp[s[i]] = i
            mpp2[s[i]] += 1
            
        for key in mpp2:
            if mpp2[key] == 1:
                return mpp[key]
        return -1
        