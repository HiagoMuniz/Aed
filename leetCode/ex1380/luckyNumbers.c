/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int index = 0;
    int num = 0, control = 0;
    int *vector = NULL;

    for ( int i = 0; i < matrixSize; i++ ){

        num = matrix[i][0];
        index = 0;
        for ( int j = 1; j < matrixColSize[0]; j++ ){
            if (matrix[i][j] < num){
                num = matrix[i][j];
                index = j;
            }
        }

        int isMaxInCol = 1;
        for (int k = 0; k < matrixSize; k++) {
            if (matrix[k][index] > num) {
                isMaxInCol = 0;
                break;
            }
        }

        if (isMaxInCol) {
            vector = realloc (vector, sizeof(int) * (control+1));
            vector[control] = num;
            control++;
        }
    }

    *returnSize = control;
    return vector;

}