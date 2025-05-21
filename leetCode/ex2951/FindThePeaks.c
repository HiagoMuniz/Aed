/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findPeaks(int* mountain, int mountainSize, int* returnSize) {
    int k = 0;
    int *vector = NULL;

    for ( int i = 1; i < mountainSize-1; i++ ){
        if (mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1] ){
            vector = (int *) realloc(vector, sizeof(int) * (k+1));
            vector[k++] = i;
        }
    }

    *returnSize = k;
    return vector;
}