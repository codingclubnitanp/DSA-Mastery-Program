def mergeArrays(a, b):
    n = len(a)
    m = len(b)
    i, j = n - 1, 0

    while i >= 0 and j < m:
        if a[i] > b[j]:
            a[i], b[j] = b[j], a[i]
            i -= 1
            j += 1
        else:
            j += 1

    a.sort()
    b.sort()

if __name__ == "__main__":
    a = [1, 5, 9, 10, 15, 20]
    b = [2, 3, 8, 13]

    mergeArrays(a, b)

    print("Array A:", a)
    print("Array B:", b)
