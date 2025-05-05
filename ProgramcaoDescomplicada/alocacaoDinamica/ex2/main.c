#include <stdio.h>

int main(void){
    int *pointer;
    int num = 0, tamVet = 0;

    scanf("%d", &tamVet);

    pointer = ( int* ) malloc( sizeof(int) * tamVet );

    for (int i = 0; i < tamVet; i++){
        scanf("%d", &num);
        pointer[i] = num;
    }

    for (int i = 0; i < tamVet; i++){
        printf("%d ", pointer[i]);
    }
    
}