#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void print_divisors(int n) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    sol.print_divisors(n);
    return 0;
}
