
bool hasZero(int x) {
    while (x > 0) {
        if (x % 10 == 0) return true;
        x /= 10;
    }
    return false;
}

int* getNoZeroIntegers(int n, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 1; i < n; i++) {
        int a = i;
        int b = n - i;
        if (!hasZero(a) && !hasZero(b)) {
            result[0] = a;
            result[1] = b;
            *returnSize = 2;
            return result;
        }
    }

    result[0] = result[1] = 0;
    *returnSize = 2;
    return result;
}
