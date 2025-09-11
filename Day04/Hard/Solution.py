class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = []
        pos = []
        for i, ch in enumerate(s):
            if ch.lower() in "aeiou":
                vowels.append(ch)
                pos.append(i)
        vowels.sort()
        s = list(s)
        for i, p in enumerate(pos):
            s[p] = vowels[i]
        return "".join(s)

if __name__ == "__main__":
    s = input("Enter a string: ")
    sol = Solution()
    print("String after sorting vowels:", sol.sortVowels(s))
