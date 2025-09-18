#include <stdio.h>

// A helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = maxSubArray(nums, numsSize);
    printf("Maximum subarray sum: %d\n", result);
    return 0;
}
