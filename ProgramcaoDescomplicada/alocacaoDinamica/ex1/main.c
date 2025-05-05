#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *pointer;
    int num;

    pointer = ( int* ) malloc( sizeof( int ) * 5);

    for( int i = 0; i < 5; i++ ){
        scanf("%d", &num);
        pointer[i] = num;
    }

    for( int i = 0; i < 5; i++ ){
        printf("%d ", (pointer)[i]);
    }

    free(pointer);
}