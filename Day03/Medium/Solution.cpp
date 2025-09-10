#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int ele = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > ele) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = ele;
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    sol.insertionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
