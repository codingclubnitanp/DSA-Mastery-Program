#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool armstrongNumber(int n) {
    int sum = 0, x = n;
    while (x > 0) {
        int d = x % 10;
        sum += pow(d, 3);
        x /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    scanf("%d", &n);
    if (armstrongNumber(n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
