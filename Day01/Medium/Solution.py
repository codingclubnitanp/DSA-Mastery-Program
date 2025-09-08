class Solution:
    def bubbleSort(self, arr):
        n = len(arr)
        for i in range(n - 1):
            flag = 0
            for j in range(1, n - i):
                if arr[j] < arr[j - 1]:
                    flag = 1
                    arr[j], arr[j - 1] = arr[j - 1], arr[j]
            if flag == 0:
                return

arr = [5, 1, 4, 2, 8]
sol = Solution()
sol.bubbleSort(arr)
print("Sorted array:", arr)
