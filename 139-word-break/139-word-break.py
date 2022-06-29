class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        @cache
        def dfs(i):
            if i == len(s):
                return True
            for ei in range(i+1, len(s)+1):
                word = s[i: ei]
                if word in wordSet and dfs(ei):
                    return True
            return False
        return dfs(0)