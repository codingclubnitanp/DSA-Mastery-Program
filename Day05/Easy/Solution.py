class Solution:
    def armstrongNumber(self, n: int) -> bool:
        total, x = 0, n
        while x > 0:
            d = x % 10
            total += d ** 3
            x //= 10
        return total == n

if __name__ == "__main__":
    n = int(input().strip())
    sol = Solution()
    print("true" if sol.armstrongNumber(n) else "false")
