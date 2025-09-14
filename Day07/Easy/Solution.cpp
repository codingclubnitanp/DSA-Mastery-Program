#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPrimeFactor(int n) {
        long long maxi = -1;
        while (n % 2 == 0) {
            n /= 2;
            maxi = 2;
        }
        for (long long i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                n /= i;
                maxi = i;
            }
        }
        if (n > 2) {
            maxi = n;
        }
        return maxi;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.largestPrimeFactor(n) << endl;
    return 0;
}
