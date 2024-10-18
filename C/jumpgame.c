#include <stdio.h>
#include <stdbool.h>

bool canJump(int *nums, int numsSize) {
    int maxReach = 0; // Initialize the maximum reachable index

    for (int i = 0; i < numsSize; i++) {
        // Check if the current index is beyond the maximum reachable index
        if (i > maxReach) {
            return false; // Cannot proceed further
        }

        // Update the maximum reachable position
        maxReach = (i + nums[i] > maxReach) ? (i + nums[i]) : maxReach;

        // If we can reach or exceed the last index, return true
        if (maxReach >= numsSize - 1) {
            return true;
        }
    }

    return false; // If we exit the loop without reaching the end
}

void testJumpAbility(int *nums, int numsSize) {
    printf("Testing array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    if (canJump(nums, numsSize)) {
        printf("Yes, you can reach the end of the array!\n");
    } else {
        printf("No, you cannot reach the end of the array.\n");
    }
}

int main() {
    // Example test cases
    int test1[] = {2, 3, 1, 1, 4};
    int test2[] = {3, 2, 1, 0, 4};
    int test3[] = {0}; // Single element case
    int test4[] = {1, 2, 3}; // Always reachable

    testJumpAbility(test1, sizeof(test1) / sizeof(test1[0]));
    testJumpAbility(test2, sizeof(test2) / sizeof(test2[0]));
    testJumpAbility(test3, sizeof(test3) / sizeof(test3[0]));
    testJumpAbility(test4, sizeof(test4) / sizeof(test4[0]));

    return 0;
}
