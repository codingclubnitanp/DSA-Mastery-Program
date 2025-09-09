#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    long long sum = 0;
    while (x != 0) {
        sum = sum * 10 + (x % 10);
        x = x / 10;
        if (sum > INT_MAX || sum < INT_MIN) {
            return 0;
        }
    }
    return (int)sum;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", reverse(n));
    return 0;
}
