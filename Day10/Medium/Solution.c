#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int candidate = 0; // Can be any initial value

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    return candidate;
}

int main() {
    int nums[] = {2, 2, 1, 1, 1, 2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = majorityElement(nums, numsSize);
    printf("Majority Element: %d\n", result);
    return 0;
}
