class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        mpp = defaultdict(lambda : 0)
        cnt = 0
        for word in words:
            mpp[word]+=1
        for word in words:
            if word in mpp and word[::-1] in mpp and mpp[word] != 0  and mpp[word[::-1]] != 0:
                if word[0] == word[1]:
                    if mpp[word] > 1:
                        cnt += 4
                        mpp[word] -= 2
                else:
                    cnt += 4
                    mpp[word] -= 1
                    mpp[word[::-1]] -= 1

        for key in mpp:
            if mpp[key] >= 1:
                if key[0] == key[1]:
                    cnt += 2
                    break
        return cnt