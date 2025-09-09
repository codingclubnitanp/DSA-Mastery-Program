MOD = 10**9 + 7

class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        dp = [0] * (n + 1)
        dp[1] = 1
        share = 0

        for day in range(2, n + 1):
            if day - delay >= 1:
                share = (share + dp[day - delay]) % MOD
            if day - forget >= 1:
                share = (share - dp[day - forget]) % MOD
            dp[day] = share

        ans = 0
        for i in range(n - forget + 1, n + 1):
            if i >= 1:
                ans = (ans + dp[i]) % MOD
        return ans

if __name__ == "__main__":
    sol = Solution()
    print(sol.peopleAwareOfSecret(6, 2, 4)) 
