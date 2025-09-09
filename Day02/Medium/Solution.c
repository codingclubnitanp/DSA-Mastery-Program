#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxi = arr[0];
        int maxiInd = 0;
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > maxi) {
                maxi = arr[j];
                maxiInd = j;
            }
        }
        int temp = arr[n - i - 1];
        arr[n - i - 1] = arr[maxiInd];
        arr[maxiInd] = temp;
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    selectionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
