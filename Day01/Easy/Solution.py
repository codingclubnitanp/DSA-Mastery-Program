class Solution:
    def countDigits(self, n: int) -> int:
        c = 0
        while n > 0:
            c += 1
            n //= 10
        return c

# Example usage
sol = Solution()
print(sol.countDigits(12345))
