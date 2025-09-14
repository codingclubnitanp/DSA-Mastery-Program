#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int i = n - 1, j = 0;

        while (i >= 0 && j < m) {
            if (a[i] > b[j]) {
                swap(a[i], b[j]);
                i--;
                j++;
            } else {
                j++;
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};

int main() {
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};

    Solution s;
    s.mergeArrays(a, b);

    cout << "Array A: ";
    for (int x : a) cout << x << " ";
    cout << "\nArray B: ";
    for (int x : b) cout << x << " ";
    cout << endl;

    return 0;
}
