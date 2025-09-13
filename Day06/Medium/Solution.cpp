#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sieve(int n) {
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int j = p * p; j <= n; j += p)
                    prime[j] = false;
            }
        }

        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (prime[i]) primes.push_back(i);
        }
        return primes;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<int> primes = sol.sieve(n);
    for (int p : primes) cout << p << " ";
    cout << endl;
    return 0;
}
