int duplicateNumbersXOR(int* nums, int numsSize) {
    int freq[51] = {0};
    int result = 0;
    int j = 0;
     for (int i = 0; i < numsSize; i++){
        freq[nums[i]]++;
     }

    for (int i = 0; i <= 50; i++){
        if ( freq[i] > 1){
            result ^= i;
        }
    }

    return result;
}