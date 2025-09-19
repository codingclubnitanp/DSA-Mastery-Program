#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    int min = INT_MAX;
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min) {
            min = prices[i];
        }
        int pr = prices[i] - min;
        if (pr > max) {
            max = pr;
        }
    }
    return max;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    printf("%d\n", maxProfit(prices, n)); // Expected: 5
    return 0;
}

