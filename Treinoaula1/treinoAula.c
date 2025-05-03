#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu();
void Adicionar(char **pointer);
void Listar(char *pointer);
void Remover(char **pointer);


int main(void){

    int decide = -1;
    char *pointer;

    pointer = malloc(1);
    pointer[0] = '\0';


    for (;;){
        
        decide = Menu();

        switch (decide)
        {
        case 1:
            Adicionar(&pointer);
            break;
        case 2:
            Remover(&pointer);
            break;
        case 3:
           Listar(pointer);
            break;
        case 4:
            free(pointer);
            exit(1);
            break;
        }

    }

}

int Menu(){
    int c;
    do
    {
        printf("\t 1. para adicionar nome\n");
        printf("\t 2. para remover nome\n");
        printf("\t 3. para listar os nome\n");
        printf("\t 4. para sair\n");
        scanf("%d", &c);
    } while (c < 1 || c > 4);
    
    return c;

}

void Remover(char **pointer) {
    char nome[100];
    char *reservePointer;
    int j = 0, tamanho = 0;
    char nomeComp[100];
    int nomeEncontrado = 0;

    printf("Qual nome você quer remover? ");
    scanf(" %[^\n]s", nome);

    tamanho = strlen(*pointer);

    for (int i = 0; i < tamanho; ) {
        j = 0;

        while ((*pointer)[i + j] != '$' && (*pointer)[i + j] != '\0') {
            nomeComp[j] = (*pointer)[i + j];
            j++;
        }
        nomeComp[j] = '\0'; 

        if (strcmp(nome, nomeComp) == 0) {
            int novoTamanho = tamanho - (j + 1); 
            reservePointer = (char *)malloc(sizeof(char) * (novoTamanho + 1));

            if (reservePointer) {

                strncpy(reservePointer, *pointer, i);
                strcpy(reservePointer + i, (*pointer) + i + j + 1);

                reservePointer[novoTamanho] = '\0'; 
                free(*pointer);

                *pointer = reservePointer;
                printf("Nome removido com sucesso\n");
                nomeEncontrado = 1;
                return;
            } else {
                printf("Erro ao realocar memória\n");
                return;
            }
        }
        i += j+1; 
    }

    if (nomeEncontrado == 0) {
        printf("Nome não encontrado.\n");
    }
}

void Adicionar(char **pointer){
    int tamanho=0;
    char nome[100];
    char *reservePointer;

    printf("Qual nome você quer adicionar?");
    scanf(" %[^\n]s", nome);

    if (*pointer){
        tamanho = (strlen(*pointer));
    }

    tamanho += strlen(nome) + 2;

    reservePointer = (char *) realloc(*pointer, sizeof(char)*tamanho);
    if (reservePointer){
        *pointer = reservePointer;
    }

    if (strlen(*pointer) == 0) {
        (*pointer)[0] = '\0';
    }

    strcat(*pointer, nome);
    strcat(*pointer, "$");
}

void Listar(char *pointer){
    char nomePrint[100];
    int count=0;

    while (*pointer != '\0'){
        if (*pointer == '$'){
            nomePrint[count] = '\0';
            printf("%s \n", nomePrint);
            count = 0;
        }else {
            nomePrint[count] = *pointer;
            count++;
        }
     pointer++;
    }
}
