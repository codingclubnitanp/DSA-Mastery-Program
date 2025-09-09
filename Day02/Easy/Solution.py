class Solution(object):
    def reverse(self, x):
        sum_val = 0
        neg = -1 if x < 0 else 1
        x = abs(x)

        while x != 0:
            sum_val = sum_val * 10 + x % 10
            x //= 10

        sum_val *= neg
        if sum_val > 2**31 - 1 or sum_val < -2**31:
            return 0
        return sum_val


if __name__ == "__main__":
    sol = Solution()
    n = int(input("Enter an integer: "))
    result = sol.reverse(n)
    print("Reversed integer:", result)
