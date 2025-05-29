#include <stdio.h>
#include <stdlib.h>

void addContact();
void remContact();
void printContact();
void listAll();
void freeAll();


int main(void){

    void *pBuffer = NULL;

    // [opcao][qtdContatos]
    pBuffer = malloc ( sizeof(int) * 2 ); 
    *((int *)(pBuffer + sizeof(int))) = 0;

    for (;;){

        printf("\n--- MENU ---\n");
        printf("1 - Adicionar Pessoa\n");
        printf("2 - Remover Pessoa\n");
        printf("3 - Buscar Pessoa\n");
        printf("4 - Listar todos\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");

        scanf("%d", (int *)pBuffer);

        switch ( * ( ( int* ) pBuffer ) )
        {
        case 1:
            //addContact();
            break;

        case 2:
            //remContact();
            break;

        case 3:
            //printContact();
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

void remContact(){
    
}

void printContact(){
    
}

void listAll(){
    
}

void freeAll(){
    
}

