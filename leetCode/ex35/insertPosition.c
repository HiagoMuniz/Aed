#include <stdlib.h>
#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target);

int main() {
    int nums[] = {1, 3, 5, 6}; // Array de exemplo
    int target = 5;            
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = searchInsert(nums, numsSize, target);

    printf("Posição para inserir ou encontrar o número %d é: %d\n", target, result);

    return 0;
}

int searchInsert(int* nums, int numsSize, int target) {
    int i = 0;
    for ( i = 0; i < numsSize; i++ ){
        if (nums[i] == target){
            return i;
        }
    }

    for ( i = 0; i < numsSize; i++ ){
        if (nums[i] > target){
            return i;
        }
    }

    return numsSize;
        


}