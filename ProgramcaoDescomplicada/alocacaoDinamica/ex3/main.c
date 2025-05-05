#include <stdio.h>

int main(void){
    int *pointer;
    int num = 0, tamVet = 0;
    int countPar = 0, countImpar = 0;

    scanf("%d", &tamVet);

    pointer = ( int* ) malloc( sizeof(int) * tamVet );

    for (int i = 0; i < tamVet; i++){
        scanf("%d", &num);
        pointer[i] = num;
        if (num % 2 == 0){
            countPar++;
        }else{
            countImpar++;
        }
    }

    printf("N de impares: %d\nN de pares: %d\n", countImpar, countPar);
    
}