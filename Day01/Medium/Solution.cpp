#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int flag = 0;
            for (int j = 1; j < n - i; j++) {
                if (arr[j] < arr[j - 1]) {
                    flag = 1;
                    swap(arr[j - 1], arr[j]);
                }
            }
            if (flag == 0) {
                return;
            }
        }
    }
};

int main() {
    vector<int> arr = {5, 1, 4, 2, 8};
    Solution sol;
    sol.bubbleSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
