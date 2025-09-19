class Solution:
    def maxProfit(self, prices):
        max = 0
        min_val = float('inf')
        for price in prices:
            min_val = min(min_val, price)
            pr = price - min_val
            max = max if pr < max else pr
        return max

if __name__ == "__main__":
    sol = Solution()
    prices = [7, 1, 5, 3, 6, 4]
    print(sol.maxProfit(prices))  # Expected: 5
