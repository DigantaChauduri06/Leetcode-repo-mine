class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # strs.sort(key=lambda x: len(x))
        # print(strs)
        word = strs[0]
        if len(word) == 1:
            for i in range(1,len(strs)):
                if not strs[i].startswith(word):
                    return ""
            return word
        for i in range(1,len(word)+1):
            pre = word[:i]
            notStarts = True
            for j in range(1, len(strs)):
                print("pre", pre)
                if not strs[j].startswith(pre):
                    notStarts = False
                    break
            if not notStarts:
                return word[:i-1]
        return word