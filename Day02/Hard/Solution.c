#include <stdio.h>

#define MOD 1000000007

int peopleAwareOfSecret(int n, int delay, int forget) {
    long long dp[n + 1];
    for (int i = 0; i <= n; i++) dp[i] = 0;
    dp[1] = 1;

    long long share = 0;
    for (int day = 2; day <= n; day++) {
        if (day - delay >= 1) {
            share = (share + dp[day - delay]) % MOD;
        }
        if (day - forget >= 1) {
            share = (share - dp[day - forget] + MOD) % MOD;
        }
        dp[day] = share;
    }

    long long ans = 0;
    for (int i = n - forget + 1; i <= n; i++) {
        if (i >= 1) ans = (ans + dp[i]) % MOD;
    }
    return (int)ans;
}

int main() {
    int n = 6, delay = 2, forget = 4;
    printf("%d\n", peopleAwareOfSecret(n, delay, forget));
    return 0;
}
