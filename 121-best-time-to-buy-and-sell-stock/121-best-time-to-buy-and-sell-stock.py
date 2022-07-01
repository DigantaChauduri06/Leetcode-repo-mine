class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 1:
            return 0
        buy, profit = int(1e9), 0
        for i in range(len(prices)):
            buy =  min(buy, prices[i])
            profit = max(profit, prices[i] - buy)
        return profit
            
            
# [7,1,5,3,6,4]

# 