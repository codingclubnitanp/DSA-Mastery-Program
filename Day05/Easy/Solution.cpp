#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool armstrongNumber(int n) {
        int sum = 0, x = n;
        while (x > 0) {
            int d = x % 10;
            sum += pow(d, 3);
            x /= 10;
        }
        return sum == n;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << (sol.armstrongNumber(n) ? "true" : "false") << endl;
    return 0;
}
