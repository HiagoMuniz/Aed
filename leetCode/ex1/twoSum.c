#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (returnSize == 2 && result != NULL) {
        printf("Índices encontrados: [%d, %d]\n", result[0], result[1]);
        free(result);  // Libera a memória alocada
    } else {
        printf("Nenhuma combinação encontrada.\n");
    }

    return 0;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   int i = 0, j = 0;
   int *pointer;

       for (i = 0; i < numsSize; i++){
           for (j = 0; j < i; j++){
               if ( (nums[j] + nums[i]) == target){
                   pointer = (int *)malloc( sizeof(int) * 2 );
                   if (pointer){
                       pointer[0] = j;
                       pointer[1] = i;
                       *returnSize = 2;
                       return pointer;
                   }
               }
           }
       }
   *returnSize = 0;
   return pointer;
}