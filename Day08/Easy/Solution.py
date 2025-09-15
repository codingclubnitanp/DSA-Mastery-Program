class Solution:
    def reverseArray(self, arr):
        i, j = 0, len(arr)-1
        while i < j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1

if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 3, 4, 5]
    sol.reverseArray(arr)
    print("Reversed array:", arr)
