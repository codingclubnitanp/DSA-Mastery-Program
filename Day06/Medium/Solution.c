#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* sieve(int n, int* size) {
    bool prime[n+1];
    for (int i = 0; i <= n; i++) prime[i] = true;
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int j = p * p; j <= n; j += p)
                prime[j] = false;
        }
    }

    int* primes = (int*)malloc((n+1) * sizeof(int));
    *size = 0;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) primes[(*size)++] = i;
    }
    return primes;
}

int main() {
    int n;
    scanf("%d", &n);
    int size;
    int* primes = sieve(n, &size);
    for (int i = 0; i < size; i++) printf("%d ", primes[i]);
    printf("\n");
    free(primes);
    return 0;
}
