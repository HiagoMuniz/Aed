bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i = 0;
    int *pointer = flowerbed;

    if ( n == 0 ){
        return true;
    }
    
    if ( flowerbedSize == 1 ){
        if (pointer[0] == 1){
            return false;
        }else{
            return true;
        }
    }
 
    if ( pointer[0] != 1 && pointer[1] != 1){
        pointer[0] = 1;
        n--;
    }

    if ( pointer[flowerbedSize-2] != 1 && pointer[flowerbedSize-1] != 1 ){
        pointer[flowerbedSize-1] = 1;
        n--;
    }

    for ( i = 1; i < flowerbedSize-1; i++ ){
        if (pointer[i-1] != 1 && pointer[i] != 1 && pointer[i+1] != 1){
            pointer[i] = 1;
            n--;
        }
    }

    if (n <= 0){
        return true;
    }

    return false;
}