#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int n, int* returnSize) {
    int* answer = (int*)malloc(n * sizeof(int));
    *returnSize = n;

    // Pass 1: prefix products
    answer[0] = 1;
    for (int i = 1; i < n; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Pass 2: multiply by suffix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}

void printArray(int* arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(",");
    }
    printf("]\n");
}

int main() {
    int nums1[] = {1, 2, 3, 4};
    int size1;
    int* res1 = productExceptSelf(nums1, 4, &size1);
    printArray(res1, size1);   // [24,12,8,6]
    free(res1);

    int nums2[] = {-1, 1, 0, -3, 3};
    int size2;
    int* res2 = productExceptSelf(nums2, 5, &size2);
    printArray(res2, size2);   // [0,0,9,0,0]
    free(res2);

    return 0;
}