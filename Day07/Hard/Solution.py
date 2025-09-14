from typing import List

class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        exact = set(wordlist)
        caseInsensitive = {}
        vowelInsensitive = {}

        def devowel(word: str) -> str:
            return ''.join('*' if c in "aeiou" else c for c in word.lower())

        for word in wordlist:
            lower = word.lower()
            dv = devowel(word)
            if lower not in caseInsensitive:
                caseInsensitive[lower] = word
            if dv not in vowelInsensitive:
                vowelInsensitive[dv] = word

        ans = []
        for q in queries:
            if q in exact:
                ans.append(q)
            elif q.lower() in caseInsensitive:
                ans.append(caseInsensitive[q.lower()])
            elif devowel(q) in vowelInsensitive:
                ans.append(vowelInsensitive[devowel(q)])
            else:
                ans.append("")
        return ans

if __name__ == "__main__":
    sol = Solution()
    wordlist = ["KiTe","kite","hare","Hare"]
    queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
    print(sol.spellchecker(wordlist, queries))
