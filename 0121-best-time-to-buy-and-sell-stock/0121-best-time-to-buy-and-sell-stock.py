class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy,sell,profit = 1e9,0,0
        for price in prices:
            # buy = min(buy, price)
            if buy > price:
                buy = price
                sell = 0
            sell = max(sell, price)
            # print(buy, sell)
            if buy != 1e9:
                profit = max((sell-buy),profit)
        return profit