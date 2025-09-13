class Solution:
    def doesAliceWin(self, s: str) -> bool:
        for c in s:
            if c in "aeiou":
                return True
        return False

if __name__ == "__main__":
    s = input().strip()
    sol = Solution()
    print("true" if sol.doesAliceWin(s) else "false")
