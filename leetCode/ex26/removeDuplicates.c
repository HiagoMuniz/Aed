#include <stdio.h>

// Your function should have this signature
int removeDuplicates(int* nums, int numsSize);

void printArray(int* nums, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int test1[] = {1, 1, 2};
    int test2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int test3[] = {};
    int test4[] = {1};
    int test5[] = {1, 1, 1, 1};
    int test6[] = {1, 2, 3, 4, 5};

    int* tests[] = {test1, test2, test3, test4, test5, test6};
    int sizes[] = {3, 10, 0, 1, 4, 5};
    int numTests = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numTests; i++) {
        printf("Test case %d: Original array: ", i + 1);
        printArray(tests[i], sizes[i]);
        int k = removeDuplicates(tests[i], sizes[i]);
        printf("After removeDuplicates: k = %d, array = ", k);
        printArray(tests[i], k);
        printf("-------------------------------\n");
    }

    return 0;
}

int removeDuplicates(int* nums, int numsSize) {
    int i = 0, j = 0, l = 0;
    int k = numsSize;

    for ( i = 0; i < numsSize; i++ ){
        for ( j = i+1; j < numsSize; j++ ){
            if (nums[i] == nums[j]){
                for (l = j; l < numsSize-1; l++){
                    nums[l] = nums[l+1];
                }
            numsSize--;
            j--;
            }
        }
    }

    return numsSize;
}
