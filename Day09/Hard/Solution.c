#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int* replaceNonCoprimes(int* nums, int n, int* resultSize) {
    int* ans = (int*)malloc(n * sizeof(int)); 
    *resultSize = 0;

    for (int i = 0; i < n; i++) {
        int curr = nums[i];
        while (*resultSize > 0 && gcd(curr, ans[*resultSize - 1]) > 1) {
            curr = lcm(curr, ans[*resultSize - 1]);
            (*resultSize)--; 
        }
        ans[(*resultSize)++] = curr;
    }
    return ans;
}

int main() {
    int nums[] = {6, 4, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    int resultSize;

    int* result = replaceNonCoprimes(nums, n, &resultSize);

    printf("Result: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // free allocated memory
    return 0;
}
