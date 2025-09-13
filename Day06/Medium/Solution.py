class Solution:
    def sieve(self, n: int):
        prime = [True] * (n + 1)
        prime[0] = prime[1] = False

        p = 2
        while p * p <= n:
            if prime[p]:
                for j in range(p * p, n + 1, p):
                    prime[j] = False
            p += 1

        return [i for i in range(2, n + 1) if prime[i]]

if __name__ == "__main__":
    n = int(input())
    sol = Solution()
    primes = sol.sieve(n)
    print(*primes)
