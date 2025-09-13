
class Solution:
    def print_divisors(self, N):
        divisors = []
        for i in range(1, int(N**0.5) + 1):
            if N % i == 0:
                divisors.append(i)
                if i != N // i:  
                    divisors.append(N // i)
        divisors.sort()
        for d in divisors:
            print(d, end=" ")
        print()

# Driver code
if __name__ == "__main__":
    N = int(input())
    ob = Solution()
    ob.print_divisors(N)
