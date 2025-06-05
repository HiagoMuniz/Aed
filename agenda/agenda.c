#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pushContact();
//void popContact();
//void findContact();
void listAll();


int main(void){

    void *pBuffer = NULL;

    // [opcao][qtdContatos][tamanhoBuffer][proximaPosicção]
    pBuffer = malloc ( sizeof(int) * 4 ); 
    int *pMenu = ( int *)  pBuffer;
    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 );

    *pAmount = 0;
    *pMenu = 0;
    *pBufferSize = sizeof(int) * 4;
    *pNextPosition = sizeof(int) * 4;

    for (;;){

    int *pMenu = ( int *)  pBuffer;

        printf( "\n--- MENU ---\n" );
        printf( "1 - Adicionar Pessoa\n" );
        printf( "2 - Remover Pessoa\n" );
        printf( "3 - Buscar Pessoa\n" );
        printf( "4 - Listar todos\n" );
        printf( "5 - Sair\n" );
        printf( "Escolha uma opção: " );

        scanf( "%d", pMenu );
        getchar();

        switch ( *pMenu )
        {
        case 1:
            pBuffer = pushContact(pBuffer);
            break;

        case 2:
            //popContact(pBuffer);
            break;

        case 3:
            //findContact(pBuffer);
            break;

        case 4:
            listAll(pBuffer);
            break;

        case 5:
            free(pBuffer);
            exit(1);
        }
    }
}


void *pushContact(void *pBuffer){

    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 

    void *tmp = realloc ( pBuffer, *pNextPosition + 3 * sizeof(int) + 100 * sizeof(char) );
    
    if (!tmp) {
        printf("Erro ao alocar memória!\n");
        return pBuffer;  
    }

    pBuffer = tmp;

    int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 

    int *pNameSize = ( int * )( pBuffer + *pNextPosition );

    printf( "\tDigite o seu nome: " );
    fgets( (char * )( pBuffer + *pNextPosition + sizeof(int) ), 50, stdin );
    char *name = (char *)(pBuffer + *pNextPosition + sizeof(int));

    name[strcspn(name, "\n")] = 0;  // remove o '\n'
    *pNameSize = strlen(name) + 1;

    *pNextPosition += sizeof( int ) + *pNameSize;

    int *pEmailSize = ( int * )( pBuffer + *pNextPosition );
    printf( "\tDigite o seu email: " );
    fgets( ( char * ) ( pBuffer + *pNextPosition + sizeof(int) ), 50, stdin );
    char *email = (char *)(pBuffer + *pNextPosition + sizeof(int));

    email[strcspn(email, "\n")] = 0;  // remove o '\n'
    *pEmailSize = strlen(email) + 1;

    *pNextPosition += sizeof(int) + *pEmailSize;

    printf( "\tDigite a sua idade: " );
    scanf( "%d", (int *)(pBuffer + *pNextPosition ) );
    getchar(); 

    *pNextPosition += ( sizeof(int) );

    *pBufferSize = *pNextPosition;

    tmp = realloc ( pBuffer, *pBufferSize );

    if (!tmp) {
        printf("Erro ao alocar memória!\n");
        return pBuffer;  
    }
    pBuffer = tmp;

    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    *pAmount += 1;

    return pBuffer;
}
/*
void popContact(void *pBuffer){
    //int *pMenu = ( int *)  pBuffer;
    //int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    //int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    //int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 


}

void findContact(void *pBuffer){
    //int *pMenu = ( int *)  pBuffer;
    //int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    //int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    //int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 


}
*/

void listAll(void *pBuffer){

    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    int *pCount = ( int *)  pBuffer;
    *pCount = 0;

    char *p = (char *)(pBuffer + sizeof(int) * 4);

    while ( *pCount < *pAmount ){

        int *pNameSize = (int *)p;
        p += sizeof(int);

        char *pName = p;
        p += *pNameSize;

        int *pEmailSize = (int *)p;
        p += sizeof(int);

        char *pEmail = p;
        p += *pEmailSize;

        int *pAge = (int *)p;
        p += sizeof(int);

        printf("Nome: %s\n", pName);
        printf("Email: %s\n", pEmail);
        printf("Idade: %d\n\n", *pAge);

        (*pCount)++;
        
    }



}



