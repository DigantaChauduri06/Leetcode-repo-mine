class Solution:
    def toh(self, N, fromm, to, aux):
        # Your code here
        if N > 0:
            self.toh(N-1, fromm, aux, to)
            print(f"move disk {N} from rod {fromm} to rod {to}")
            self.toh(N-1, aux, to, fromm)
        return ((2 ** N) - 1)

s = Solution()

print(s.toh(3, 1, 3, 2))
