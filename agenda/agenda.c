#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *PushContact();
void *PopContact();
void *FindContact();
void ListAll();


int main(void){

    void *pBuffer = NULL;

    // [opcao][qtdContatos][tamanhoBuffer][proximaPosicção][contato1][...]
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

        do {
            printf( "\n------- MENU -------\n" );
            printf( "1 - Adicionar Pessoa\n" );
            printf( "2 - Remover Pessoa\n" );
            printf( "3 - Buscar Pessoa\n" );
            printf( "4 - Listar todos\n" );
            printf( "5 - Sair\n\n" );
            printf( "Escolha uma opção (de 1 a 5): " );

            scanf( "%d", pMenu );
            getchar();

        } while ( *pMenu < 1 || *pMenu > 5 ); 

        switch ( *pMenu )
        {
        case 1:
            pBuffer = PushContact( pBuffer );
            break;
        case 2:
            pBuffer = PopContact( pBuffer );
            break;
        case 3:
            pBuffer = FindContact( pBuffer );
            break;
        case 4:
            ListAll( pBuffer );
            break;
        case 5:
            printf( "\n Exiting... \n" );
            free(pBuffer);
            exit(1);
        }
    }
}


void *PushContact(void *pBuffer){

    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 

    void *tmp = realloc ( pBuffer, *pNextPosition + 3 * sizeof(int) + 100 * sizeof(char) );
    
    if (!tmp) {
        printf( "Erro ao alocar memória!\n" );
        return pBuffer;  
    }
    pBuffer = tmp;

    int *pBufferSize = ( int *)  ( pBuffer + sizeof(int) * 2 );
    pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 

    int *pNameSize = ( int * )( pBuffer + *pNextPosition );

    printf( "\tDigite o seu nome: " );
    fgets( ( char * )( pBuffer + *pNextPosition + sizeof(int) ), 50, stdin );
    char *name = ( char * )( pBuffer + *pNextPosition + sizeof( int ) );

    name[ strcspn( name, "\n" ) ] = 0;
    *pNameSize = strlen( name ) + 1;

    *pNextPosition += sizeof( int ) + *pNameSize;

    int *pEmailSize = ( int * )( pBuffer + *pNextPosition );
    printf( "\tDigite o seu email: " );
    fgets( ( char * ) ( pBuffer + *pNextPosition + sizeof(int) ), 50, stdin );
    char *email = ( char * )( pBuffer + *pNextPosition + sizeof( int ) );

    email[ strcspn( email, "\n" ) ] = 0;
    *pEmailSize = strlen( email ) + 1;

    *pNextPosition += sizeof( int ) + *pEmailSize;

    printf( "\tDigite a sua idade: " );
    scanf( "%d", ( int * )( pBuffer + *pNextPosition ) );
    getchar(); 

    *pNextPosition += ( sizeof(int) );

    *pBufferSize = *pNextPosition;

    tmp = realloc ( pBuffer, *pBufferSize );

    if ( !tmp ) {
        printf( "Erro ao alocar memória!\n" );
        return pBuffer;  
    }
    pBuffer = tmp;

    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    *pAmount += 1;

    return pBuffer;
}


void *PopContact( void *pBuffer ){
    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 

    void *tmp = realloc ( pBuffer, *pNextPosition + 50 * sizeof(char) );

    if ( !tmp ){
        printf( "Erro ao alocar memória!\n" );
    }

    pBuffer = tmp;

    int *pCount = ( int *)  pBuffer;
    int *pAmount = ( int *)  ( pBuffer + sizeof(int) );
    pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 
    
    *pCount = 0;
    char *p = (char *)( pBuffer + sizeof(int) * 4 );

    printf( "\n\tDigite o nome do contato (REMOVER): " );
    fgets( ( char * )( pBuffer + *pNextPosition ), 50, stdin );
    char *pNamePop = ( char * ) ( pBuffer + *pNextPosition );

    pNamePop[ strcspn( pNamePop, "\n" ) ] = 0;

    while ( *pCount < *pAmount ){
        char *pContactStart = p;

        int *pNameSize = ( int * )p;
        p += sizeof( int );

        char *pName = p;
        p += *pNameSize;

        int *pEmailSize = ( int * )p;
        p += sizeof(int);

        char *pEmail = p;
        p += *pEmailSize;

        int *pAge = ( int * )p;
        p += sizeof( int );

        if ( ( strcmp( pName, pNamePop ) ) == 0 ){
            *pCount =  ( sizeof(int) + *pNameSize + sizeof(int) + *pEmailSize + sizeof(int) );

            memmove(
                pContactStart,
                p,
                ( (char *) pBuffer + *pNextPosition) - (char *)p
            );

            *pNextPosition -= *pCount;
            ( *pAmount )--;

            printf( "\nContato removido com sucesso!\n" );
            return pBuffer;
        }

        (*pCount)++;
    }

    printf( "\nNome não encontrado!\n" );

    tmp = realloc ( pBuffer, *pNextPosition );

    // Reajusta a memória para eliminar o nome temporário
    if ( !tmp ){
        printf( "Erro ao alocar memória!\n" );
        return pBuffer; 
    }
    pBuffer = tmp;

    return pBuffer;

}


void *FindContact( void *pBuffer ){

    int *pNextPosition = ( int *)  ( pBuffer + sizeof(int) * 3 ); 

    void *tmp = realloc ( pBuffer, *pNextPosition + 50 * sizeof(char) );

    if ( !tmp ){
        printf( "Erro ao alocar memória!\n" );
    }
    pBuffer = tmp;

    int *pCount = ( int * )  pBuffer;
    int *pAmount = ( int * )  ( pBuffer + sizeof(int) );
    pNextPosition = ( int * )  ( pBuffer + sizeof(int) * 3 ); 
    
    *pCount = 0;
    char *p = ( char * )( pBuffer + sizeof(int) * 4 );

    printf( "\n\tDigite o nome (PESUISAR): " );
    fgets( (char * )( pBuffer + *pNextPosition ), 50, stdin );
    char *pNameCompare = ( char * ) ( pBuffer + *pNextPosition );

    pNameCompare[ strcspn ( pNameCompare, "\n" ) ] = 0;  

    while ( *pCount < *pAmount ){

        int *pNameSize = ( int * )p;
        p += sizeof( int );

        char *pName = p;
        p += *pNameSize;

        int *pEmailSize = ( int * )p;
        p += sizeof( int );

        char *pEmail = p;
        p += *pEmailSize;

        int *pAge = ( int * )p;
        p += sizeof( int );

        if ( strncmp( pName, pNameCompare, *pNameSize ) == 0 ){

            printf( "\n============||============\n\n" );
            printf( "\tNome encontrado!\n\n" );
            printf( "Nome: %s\n", pName );
            printf( "Email: %s\n", pEmail );
            printf( "Idade: %d\n", *pAge );
            printf( "\n============||============\n\n" );
            break;
        }
        ( *pCount )++;
    }

    if ( *pAmount == *pCount ){
        printf( "\n Nome não encontrado! \n" );
    }

    tmp = realloc ( pBuffer, *pNextPosition );

    if ( !tmp ){
        printf( "Erro ao alocar memória!\n" );
    }
    pBuffer = tmp;

    return pBuffer;
}

void ListAll( void *pBuffer ){

    int *pAmount = ( int * )  ( pBuffer + sizeof(int) );
    int *pCount = ( int * )  pBuffer;
    *pCount = 0;

    char *p = ( char * )( pBuffer + sizeof(int) * 4 );

    while ( *pCount < *pAmount ){

        int *pNameSize = ( int * )p;
        p += sizeof( int );

        char *pName = p;
        p += *pNameSize;

        int *pEmailSize = ( int * )p;
        p += sizeof( int );

        char *pEmail = p;
        p += *pEmailSize;

        int *pAge = ( int * )p;
        p += sizeof( int );

        printf( "\n============||============\n\n" );
        printf( "Nome: %s\n", pName );
        printf( "Email: %s\n", pEmail );
        printf( "Idade: %d\n", *pAge );

        ( *pCount )++;   
    }
}



