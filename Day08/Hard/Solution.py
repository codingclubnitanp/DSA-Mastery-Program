class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        broken = False
        ans = 0

        for i in range(len(text)):
            if text[i] == ' ':
                if not broken:
                    ans += 1
                broken = False

            for j in range(len(brokenLetters)):
                if text[i] == brokenLetters[j]:
                    broken = True

        if not broken:
            ans += 1

        return ans


if __name__ == "__main__":
    text = "hello world"
    brokenLetters = "ad"

    sol = Solution()
    result = sol.canBeTypedWords(text, brokenLetters)

    print("Number of words that can be typed:", result)
