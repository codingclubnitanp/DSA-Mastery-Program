#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

class Solution {
public:
    int print2largest(vector<int>& arr) {
        int largest = -1;
        int second_largest = -1;

        for (int x : arr) {
            if (x > largest) {
                second_largest = largest;
                largest = x;
            } else if (x > second_largest && x != largest) {
                second_largest = x;
            }
        }
        return second_largest;
    }
};

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    Solution sol;
    int result = sol.print2largest(arr);
    cout << "Second largest element: " << result << endl;
    return 0;
}
