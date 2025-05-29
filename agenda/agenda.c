#include <stdio.h>
#include <stdlib.h>

void pushContact();
void popContact();
void findContact();
void listAll();
void freeAll();


int main(void){

    void *pBuffer = NULL;

    // [opcao][qtdContatos][tamanhoBuffer][proximaPosicção]
    pBuffer = malloc ( sizeof(int) * 4 ); 
    int *pMenu = ( int *)  pBuffer;
    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 );



    for (;;){

        printf( "\n--- MENU ---\n" );
        printf( "1 - Adicionar Pessoa\n" );
        printf( "2 - Remover Pessoa\n" );
        printf( "3 - Buscar Pessoa\n" );
        printf( "4 - Listar todos\n" );
        printf( "5 - Sair\n" );
        printf( "Escolha uma opção: " );

        scanf( "%d", pMenu );

        switch ( *pMenu )
        {
        case 1:
            *((int *)(pBuffer + sizeof(int))) += 1;
            //pushContact();
            break;

        case 2:
            //popContact();
            break;

        case 3:
            //findContact();
            break;

        case 4:
            //listAll();
            break;

        case 5:
            //freeAll();
            exit(1);
        }
    }
}


void addContact(){
    
}

void popContact(){
    
}

void findContact(){
    
}

void listAll(){
    
}

void freeAll(){
    
}

