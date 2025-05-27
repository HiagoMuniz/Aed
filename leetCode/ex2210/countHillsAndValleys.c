int goLeft(int indice, int* nums);
int goRight(int indice, int* nums, int numsSize);

int countHillValley(int* nums, int numsSize) {
    int count = 0;
    int indexDir = -1, indexEsq = -1;



    for ( int i = 1; i < numsSize-1; i++ ){

        int direita = goRight(i, nums, numsSize);
        int esquerda = goLeft(i, nums);

        if ( i < indexDir && i > indexEsq){
            continue;
        }
        else if ( nums[i] < nums[direita] && nums[i] < nums[esquerda] ||
            nums[i] > nums[direita] && nums[i] > nums[esquerda]){
                count++;
                indexDir = direita;
                indexEsq = esquerda;
        }


    }

    return count;
}

int goLeft(int indice, int* nums){
    
    for ( int i = indice -1; i >= 0; i--){
        if ( nums[i] != nums[indice])
            return i;
    }
    return indice;
}

int goRight(int indice, int* nums, int numsSize){
    
    for ( int i = indice + 1; i < numsSize ; i++){
        if ( nums[i] != nums[indice])
            return i;
    }
    return indice;

}