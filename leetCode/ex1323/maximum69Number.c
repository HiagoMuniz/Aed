#include <stdio.h>
#include <stdlib.h>

int maximum69Number (int num);

int main() {
    int num = 9669;
    int result = maximum69Number(num);
    printf("Resultado: %d\n", result); // Esperado: 9969
    return 0;
}

int maximum69Number (int num) {
    int *vec = NULL;
    int i = 0, j = 0, y = 1;


    while ( num != 0 ){
        
        vec = (int *) realloc (vec, sizeof(int) * (i+1) );

        vec[i] = num % 10;
        num /= 10;

        i++;
    }

    for ( j = i-1; j >= 0; j-- ){
        if (vec[j] == 6){
            vec[j] = 9;
            break;
        }
    }

    num = 0;
    for ( j = 0; j < i; j++ ){
        num += vec[j] * y;
        y *= 10;
    }

    free(vec);
    return num;
    
}