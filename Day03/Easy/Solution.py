class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        n = x
        rev = 0
        while n != 0:
            rev = rev * 10 + (n % 10)
            n = n // 10
        return rev == x

if __name__ == "__main__":
    sol = Solution()
    num = int(input("Enter a number: "))
    if sol.isPalindrome(num):
        print(f"{num} is a palindrome.")
    else:
        print(f"{num} is not a palindrome.")
