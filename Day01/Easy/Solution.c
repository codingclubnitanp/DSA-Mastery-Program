#include <stdio.h>

int countDigits(int n) {
    int c = 0;
    while (n > 0) {
        c++;
        n = n / 10;
    }
    return c;
}

int main() {
    printf("%d\n", countDigits(12345)); // Example usage
    return 0;
}
