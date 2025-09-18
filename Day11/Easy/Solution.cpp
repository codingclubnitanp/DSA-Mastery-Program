#include <iostream>
using namespace std;

int largest(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    int arr[] = {1, 8, 7, 56, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << largest(arr, n);
    return 0;
}
