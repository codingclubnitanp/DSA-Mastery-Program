class Solution:
    def common(self, languages, u, v):
        for a in languages[u]:
            for b in languages[v]:
                if a == b:
                    return True
        return False

    def minimumTeachings(self, n, languages, friendships):
        st = set()
        for u, v in friendships:
            if not self.common(languages, u - 1, v - 1):
                st.add(u)
                st.add(v)

        if not st:
            return 0

        mpp = {}
        maxi = float("-inf")
        for person in st:
            for lang in languages[person - 1]:
                mpp[lang] = mpp.get(lang, 0) + 1
                maxi = max(maxi, mpp[lang])

        return len(st) - maxi

if __name__ == "__main__":
    sol = Solution()

    n = 3
    languages = [[2], [1, 3], [1, 2]]
    friendships = [[1, 2], [1, 3], [2, 3]]

    print("Minimum Teachings:", sol.minimumTeachings(n, languages, friendships))
