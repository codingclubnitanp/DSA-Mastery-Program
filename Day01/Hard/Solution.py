class Solution:
    def hasZero(self, x):
        return '0' in str(x)

    def getNoZeroIntegers(self, n):
        for i in range(1, n):
            a, b = i, n - i
            if not self.hasZero(a) and not self.hasZero(b):
                return [a, b]
        return [0, 0]

sol = Solution()
print(sol.getNoZeroIntegers(1317))

