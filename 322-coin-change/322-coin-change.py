class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        dp = [amount+1] * (amount+1)
        dp[0] = 0
        for i in range(1, len(dp)):
            for coin in coins:
                if i - coin >= 0:
                    dp[i] = min(dp[i], 1 + dp[i - coin])
        # print(dp[-1] == (amount+1))
        return -1 if dp[-1] == (amount+1) else dp[-1]