#include <stdio.h>

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

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", largestPrimeFactor(n));
    return 0;
}
