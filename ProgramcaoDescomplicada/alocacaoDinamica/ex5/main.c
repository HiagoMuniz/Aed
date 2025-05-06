#include <stdio.h>
#include <stdlib.h>

int main(void){
    int tamVetor;
    int *pointer;
    int i = 0, num = 0, numComp = 0, count = 0;

    scanf( "%d", &tamVetor );

    pointer = ( int* ) malloc ( sizeof(int) * tamVetor );

    for ( i = 0; i < tamVetor; i++ ){
        scanf( "%d", &num );
        pointer[i] = num;
    }

    scanf( "%d", &numComp );

    for ( i = 0; i < tamVetor; i++ ){
        if ( pointer[i] % numComp == 0 ){
            count++;
        }
    }

    printf( "%d", count );
     
}