class Solution:
    def largestPrimeFactor(self, n):
        maxi = -1
        while n % 2 == 0:
            n //= 2
            maxi = 2
        i = 3
        while i * i <= n:
            while n % i == 0:
                n //= i
                maxi = i
            i += 2
        if n > 2:
            maxi = n
        return maxi

if __name__ == "__main__":
    n = int(input())
    sol = Solution()
    print(sol.largestPrimeFactor(n))
