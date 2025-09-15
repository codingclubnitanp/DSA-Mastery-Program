#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = n-1;
        while(i < j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    sol.reverseArray(arr);

    cout << "Reversed array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
