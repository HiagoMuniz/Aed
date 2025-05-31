#include <stdio.h>
#include <stdlib.h>

void pushContact();
//void popContact();
//void findContact();
//void listAll();
//void freeAll();


int main(void){

    void *pBuffer = NULL;

    // [opcao][qtdContatos][tamanhoBuffer][proximaPosicção]
    pBuffer = malloc ( sizeof(int) * 4 ); 
    int *pMenu = ( int *)  pBuffer;
    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 );

    *pAmount = 0;
    *pBufferSize = sizeof(int) * 4;
    *pNextPosition = sizeof(int) * 4;

    for (;;){

    int *pMenu = ( int *)  pBuffer;
    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 

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
            pushContact(pBuffer);
            break;

        case 2:
            //popContact(pBuffer);
            break;

        case 3:
            //findContact(pBuffer);
            break;

        case 4:
            //listAll(pBuffer);
            break;

        case 5:
            //freeAll(pBuffer);
            exit(1);
        }
    }
}


void pushContact(void *pBuffer){

    int *pMenu = ( int *)  pBuffer;
    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 


    pBuffer = realloc ( pBuffer, *pNextPosition + 3 * sizeof(int) + 100 * sizeof(char) );
    *pBufferSize += 3 * sizeof(int) + 2 * 50 * sizeof(char);

    int *pNameSize = (int *)(pBuffer + *pNextPosition);
    printf("\tDigite o seu nome: ");
    fgets((char *)(pBuffer + *pNextPosition + sizeof(int) ), 50, stdin);
    *pNameSize = strlen((char *)(pBuffer + *pNextPosition + sizeof(int) )) + 1;

    *pNextPosition += sizeof(int) + *pNameSize;

    int *pEmailSize = (int *)(pBuffer + *pNextPosition);
    printf("\tDigite o seu email: ");
    fgets((char *)(pBuffer + *pNextPosition + sizeof(int) ), 50, stdin);
    *pEmailSize = strlen((char *)(pBuffer + *pNextPosition + sizeof(int) )) + 1;

    *pNextPosition += sizeof(int) + *pEmailSize;

    int *pAge = (int *)(pBuffer + *pNextPosition);
    printf("\tDigite a sua idade: ");
    scanf("%d", (int *)(pBuffer + *pNextPosition));
    getchar(); 

    *pNextPosition += ( sizeof(int) );

    *pBufferSize = *pNextPosition;

    pBuffer = realloc ( pBuffer, *pBufferSize );

    *pAmount += 1;
}

void popContact(void *pBuffer){
    int *pMenu = ( int *)  pBuffer;
    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 


}

void findContact(void *pBuffer){
    int *pMenu = ( int *)  pBuffer;
    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 


}

void listAll(void *pBuffer){
    int *pMenu = ( int *)  pBuffer;
    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 


}

void freeAll(void *pBuffer){
    int *pMenu = ( int *)  pBuffer;
    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 

}

