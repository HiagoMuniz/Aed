#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize);

int main() {
    int bills[] = {5, 5, 5, 10, 20}; // Exemplo de entrada
    int billsSize = sizeof(bills) / sizeof(bills[0]);

    if (lemonadeChange(bills, billsSize)) {
        printf("Troco possível para todos os clientes.\n");
    } else {
        printf("Não é possível dar o troco corretamente.\n");
    }

    return 0;
}

bool lemonadeChange(int* bills, int billsSize) {
    int *pointer = bills;
    int bilVector[3] = {0};
    int i = 0;


    for ( i = 0; i < billsSize; i++ ){
        if (pointer[i] == 5){
            bilVector[0] += 1;
        } 
        else if ( pointer[i] == 10){
            bilVector[0] -= 1;
            bilVector[1] += 1;
            if ( bilVector[0] < 0){
                return false;
            }
        }
        else{
            if ( bilVector[1] > 0 ){
                
                bilVector[1] -= 1;
                bilVector[0] -= 1;
                if ( bilVector[0] < 0 ){
                    return false;
                }
            }else{
                bilVector[0] -= 3;
                if ( bilVector[0] < 0){
                    return false;
                }
            }
        }
    }

    return true;
    
}
