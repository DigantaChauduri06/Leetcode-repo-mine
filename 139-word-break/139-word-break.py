# https://leetcode.com/problems/word-break/discuss/1455100/Python-3-solutions%3A-Top-down-DP-Bottom-up-DP-then-Optimised-with-Trie-Clean-and-Concise
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n+1)
        dp[n] = True
        wordSet = set(wordDict)
        # we are marking each and every word end as True if they found in wordSet
        # and checking the first letter that we can potentially find or not
        for i in range(n-1, -1, -1):
            for j in range(i+1, n+1):
                word = s[i:j]
                if dp[j] and word in wordSet:
                    dp[i] = True
                    break
        return dp[0]