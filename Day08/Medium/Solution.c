#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

int cmp(const void* a, const void* b) {
    return ((Pair*)a)->val - ((Pair*)b)->val;
}

void twoSum(int* nums, int n, int target, int* res) {
    Pair* arr = (Pair*)malloc(n * sizeof(Pair));
    for(int i=0;i<n;i++){
        arr[i].val = nums[i];
        arr[i].idx = i;
    }
    qsort(arr, n, sizeof(Pair), cmp);

    int i=0, j=n-1;
    while(i < j){
        int sum = arr[i].val + arr[j].val;
        if(sum == target){
            res[0] = arr[i].idx;
            res[1] = arr[j].idx;
            free(arr);
            return;
        } else if(sum < target){
            i++;
        } else {
            j--;
        }
    }
    res[0] = res[1] = -1;
    free(arr);
}

int main() {
    int nums[] = {2,7,11,15};
    int target = 9;
    int res[2];
    twoSum(nums, 4, target, res);
    printf("%d %d\n", res[0], res[1]);
    return 0;
}
