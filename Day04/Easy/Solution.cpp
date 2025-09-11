#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while (a > 0 && b > 0) {
            if (a >= b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        if (a == 0) return b;
        return a;
    }
};

int main() {
    Solution sol;
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD is: " << sol.gcd(a, b) << endl;
    return 0;
}
