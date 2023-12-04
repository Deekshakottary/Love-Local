#include <stdio.h>
#include <stdlib.h>

// Function to find elements that appear more than ⌊ n/3 ⌋ times
int* majorityElement(int nums[], int numsSize, int* returnSize) {
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

    // Step 1: Find candidates
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Step 2: Count occurrences of candidates
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }

    // Step 3: Check if candidates appear more than ⌊ n/3 ⌋ times
    int threshold = numsSize / 3;
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 0;

    if (count1 > threshold) {
        result[(*returnSize)++] = candidate1;
    }
    if (count2 > threshold && candidate1 != candidate2) {
        result[(*returnSize)++] = candidate2;
    }

    return result;
}

int main() {
    int n;

    // Get user input for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int nums[n];

    // Get user input for the elements of the array
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* result = majorityElement(nums, n, &returnSize);

    // Print the elements that appear more than ⌊ n/3 ⌋ times
    printf("Elements that appear more than ⌊ n/3 ⌋ times: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free allocated memory
    free(result);

    return 0;
}