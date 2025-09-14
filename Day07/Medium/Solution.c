#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void mergeArrays(int a[], int n, int b[], int m) {
    int i = n - 1, j = 0;
    while (i >= 0 && j < m) {
        if (a[i] > b[j]) {
            int temp = a[i];
            a[i] = b[j];
            b[j] = temp;
            i--;
            j++;
        } else {
            j++;
        }
    }
    qsort(a, n, sizeof(int), cmpfunc);
    qsort(b, m, sizeof(int), cmpfunc);
}

int main() {
    int a[] = {1, 5, 9, 10, 15, 20};
    int b[] = {2, 3, 8, 13};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    mergeArrays(a, n, b, m);

    printf("Array A: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\nArray B: ");
    for (int i = 0; i < m; i++) printf("%d ", b[i]);
    printf("\n");

    return 0;
}
