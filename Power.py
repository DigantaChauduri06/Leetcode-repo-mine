MOD = int(1e9+7)

class Solution:
    #Complete this function
    def power(self,N,R):
        #Your code here
        if R == 0:
          return 1
        if R == 1:
            return N
        smaller1, smaller2 = 1,1
        if R & 1:
            smaller1 = (N * self.power(N, R - 1)) % MOD
        else:
            smaller2 = (self.power(N, R // 2) * self.power(N, R // 2)) % MOD
        
        return (smaller1 * smaller2) % MOD

s = Solution()
print(s.power(2, 5))