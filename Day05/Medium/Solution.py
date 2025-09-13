class Solution:
    def partition(self, arr, low, high):
        i, j = low, high
        pivot = arr[low]
        while i < j:
            while i < high and arr[i] <= pivot:
                i += 1
            while j > low and arr[j] > pivot:
                j -= 1
            if i < j:
                arr[i], arr[j] = arr[j], arr[i]
        arr[low], arr[j] = arr[j], arr[low]
        return j

    def quickSort(self, arr, low, high):
        if low < high:
            p = self.partition(arr, low, high)
            self.quickSort(arr, low, p - 1)
            self.quickSort(arr, p + 1, high)

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    sol = Solution()
    sol.quickSort(arr, 0, n - 1)
    print(*arr)
