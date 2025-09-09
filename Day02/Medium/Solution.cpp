#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void selectionSort(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int mini = arr[0];
            int miniInd = 0;
            for (int j = 0; j < n - i; j++) {
                if (arr[j] > mini) { 
                    mini = arr[j];
                    miniInd = j;
                }
            }
            swap(arr[n - i - 1], arr[miniInd]);
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

    sol.selectionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
