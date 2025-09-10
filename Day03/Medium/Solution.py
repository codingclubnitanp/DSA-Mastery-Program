class Solution:
    def insertionSort(self, arr):
        n = len(arr)
        for i in range(1, n):
            ele = arr[i]
            j = i - 1
            while j >= 0 and arr[j] > ele:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = ele

if __name__ == "__main__":
    sol = Solution()
    n = int(input("Enter number of elements: "))
    arr = list(map(int, input("Enter elements: ").split()))

    sol.insertionSort(arr)

    print("Sorted array:", *arr)
