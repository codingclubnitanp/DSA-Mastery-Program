#include <stdio.h>

int findSecondLargest(int arr[], int n) {
    int largest = -1;
    int second_largest = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = findSecondLargest(arr, n);
    printf("Second largest element: %d\n", result);
    return 0;
}
