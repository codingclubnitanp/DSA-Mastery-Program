class Solution:
    def selectionSort(self, arr):
        n = len(arr)
        for i in range(n - 1):
            maxi = arr[0]
            maxiInd = 0
            for j in range(n - i):
                if arr[j] > maxi:
                    maxi = arr[j]
                    maxiInd = j
            arr[n - i - 1], arr[maxiInd] = arr[maxiInd], arr[n - i - 1]

if __name__ == "__main__":
    sol = Solution()
    n = int(input("Enter number of elements: "))
    arr = list(map(int, input("Enter elements: ").split()))

    sol.selectionSort(arr)

    print("Sorted array:", *arr)
