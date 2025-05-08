#include <stdio.h>
#include <stdlib.h>


int** generate(int numRows, int* returnSize, int** returnColumnSizes);

int main() {
    int numRows = 5;
    int returnSize;
    int* returnColumnSizes;
    int** triangle = generate(numRows, &returnSize, &returnColumnSizes);

    printf("Pascal's Triangle with %d rows:\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; i++) {
        free(triangle[i]);
    }
    free(triangle);
    free(returnColumnSizes);

    return 0;
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int i = 0, j = 0, k = 0;
    int **pointer = NULL;

    *returnColumnSizes = (int*) malloc(sizeof(int) * numRows);
    
    pointer = (int **) malloc (sizeof(int*) * numRows);

    for ( i = 0; i < numRows; i++ ){
        pointer[i] = (int*) malloc( sizeof(int) * (j+1));
        pointer[i][0] = 1;
        pointer[i][i] = 1;
        (*returnColumnSizes)[i] = i+1;
        j++;
    }

    for( i = 2; i < numRows; i++ ){
        for ( k = 1; k < i; k++ ){
            pointer[i][k] = pointer[i-1][k] + pointer[i-1][k-1];
        }
    }
    *returnSize = numRows;
    return pointer;


}