class Solution:
    def gcd(self, a: int, b: int) -> int:
        while a > 0 and b > 0:
            if a >= b:
                a = a % b
            else:
                b = b % a
        if a == 0:
            return b
        return a

if __name__ == "__main__":
    a = int(input("Enter first number: "))
    b = int(input("Enter second number: "))
    sol = Solution()
    print("GCD is:", sol.gcd(a, b))
