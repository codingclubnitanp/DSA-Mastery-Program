class Solution:
    def maxFreqSum(self, s: str) -> int:
        freq = {}
        vowel, conso = 0, 0
        for c in s:
            freq[c] = freq.get(c, 0) + 1
            if c in "aeiou":
                vowel = max(vowel, freq[c])
            else:
                conso = max(conso, freq[c])
        return vowel + conso

if __name__ == "__main__":
    s = input().strip()
    sol = Solution()
    print(sol.maxFreqSum(s))
