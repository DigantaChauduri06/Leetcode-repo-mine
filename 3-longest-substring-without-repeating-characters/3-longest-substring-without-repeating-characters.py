class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last = set()
        longest = 0
        j = 0
        i = 0
        while i < len(s):
            if not s[i] in last:
                longest = max(longest,(i - j + 1))
                last.add(s[i])
                i+=1
            else:
                last.remove(s[j])
                j+=1
        return longest
        
        