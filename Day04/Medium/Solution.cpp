#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> res(r - l + 1);
        int i = l, j = mid + 1, c = 0;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) res[c++] = arr[i++];
            else res[c++] = arr[j++];
        }
        while (i <= mid) res[c++] = arr[i++];
        while (j <= r) res[c++] = arr[j++];

        for (int k = 0; k < c; k++) arr[l + k] = res[k];
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    sol.mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
