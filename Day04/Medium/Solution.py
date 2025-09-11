class Solution:
    def merge(self, arr, l, mid, r):
        res = []
        i, j = l, mid + 1

        while i <= mid and j <= r:
            if arr[i] <= arr[j]:
                res.append(arr[i])
                i += 1
            else:
                res.append(arr[j])
                j += 1

        while i <= mid:
            res.append(arr[i])
            i += 1
        while j <= r:
            res.append(arr[j])
            j += 1

        for k in range(len(res)):
            arr[l + k] = res[k]

    def mergeSort(self, arr, l, r):
        if l < r:
            mid = (l + r) // 2
            self.mergeSort(arr, l, mid)
            self.mergeSort(arr, mid + 1, r)
            self.merge(arr, l, mid, r)


if __name__ == "__main__":
    n = int(input("Enter size of array: "))
    arr = list(map(int, input("Enter elements: ").split()))

    sol = Solution()
    sol.mergeSort(arr, 0, n - 1)

    print("Sorted array:", *arr)
