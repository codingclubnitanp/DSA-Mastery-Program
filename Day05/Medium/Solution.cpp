#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int p = partition(arr, low, high);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        int i = low, j = high;
        int pivot = arr[low];
        while (i < j) {
            while (arr[i] <= pivot && i < high) i++;
            while (arr[j] > pivot && j > low) j--;
            if (i < j) swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution sol;
    sol.quickSort(arr, 0, n - 1);

    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
