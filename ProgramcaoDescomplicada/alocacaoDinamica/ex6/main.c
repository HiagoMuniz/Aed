#include <stdio.h>
#include <stdlib.h>

int Menu();
void consultar(int *memoria, int tam);
void inserir(int *memoria, int tam);


int main(void){
    int *pointer;
    int tamMem = 0;
    int decide = -1;

    printf( "Qual tamanho de memória do seu pc? " );
    scanf( "%d", &tamMem );

    pointer = ( int* ) malloc ( sizeof(int) * tamMem );

    for ( int i = 0; i < tamMem; i++ ){
        pointer[i] = 0;
    }
    

    for ( ; ; ){

        decide = Menu();

        switch (decide)
        {
        case 1:
            inserir(pointer, tamMem);
            break;

        case 2:
            consultar(pointer, tamMem);
            break;

        case 3:
            free(pointer);
            exit(1);
            break;
        }
        
    }
}

void inserir(int *memoria, int tam){
    int posicao, valor;


    printf("Em qual posição você quer inserir\n");
    do {
        scanf( "%d", &posicao );
    } while ( posicao < 0 || posicao > tam - 1 );

    printf( "Qual valor você quer por nesta posicao?\n" );
    scanf( "%d", &valor);

    memoria[posicao] = valor;
}

void consultar(int *memoria, int tam){
    int posicao;

    printf("Qual posicao você quer consultar?\n");
    do
    {
        scanf( "%d", &posicao );
    } while (posicao < 0 || posicao >= tam);

    printf("o valor desta posicao e: %d\n", memoria[posicao]);
    
    
}


int Menu(){
    int c;

    do{
        printf("\t 1. Inserir valor\n");
        printf("\t 2. consultar valor\n");
        printf("\t 3. sair\n");
        scanf( "%d", &c );
    }while ( c < 1 || c > 3 );

    return c;
}