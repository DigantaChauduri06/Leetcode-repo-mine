class Solution:
    def isPalin(self, i,j, s):
        while i < j:
            if s[i].lower() != s[j].lower():
                return False
            i+=1
            j-=1
        return True
    def isPalindrome(self, s: str) -> bool:
        def fun(ch):
            small_char = [chr(ord('a') + i) for i in range(26)]
            long_char = [chr(ord('A') + i) for i in range(26)]
            alpha_numaric = [chr(ord("0") + i) for i in range(10)]
            if ch in small_char or ch in long_char or ch in alpha_numaric:
                return True
            else:
                return False
        filtered = list(s)
        filtered = list(filter(fun, filtered))

        filtered = "".join(filtered)
        # print(filtered)
        i,j = 0,len(filtered)-1
        return self.isPalin(i,j,filtered)
        