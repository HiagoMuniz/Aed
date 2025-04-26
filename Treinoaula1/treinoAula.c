#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu();
void Adicionar(char stringNomes[], int ultimoIndex);

int main(void){

    int decide = -1;
    char stringNomes[0];
    int ultimoIndex = 0;
    int tamStrings[100];
    for (;;){
        
        decide = Menu();

        switch (decide)
        {
        case 1:
            Adicionar(stringNomes, ultimoIndex);
            break;
        case 2:
            //Remover();
            break;
        case 3:
           //Listar();
            break;
        case 4:
            exit(1);
            break;
        }

    }

}

int Menu(){
    int c;
    printf("\t 1. para adicionar nome\n");
    printf("\t 2. para remover nome\n");
    printf("\t 3. para listar os nome\n");
    printf("\t 4. para sair\n");
    scanf("%d", &c);
    return c;

}

void Adicionar(char stringNomes[], int ultimoIndex){
    int tamanho = 0;
    char nome[100];
    char *pointer;

    int tamanhoAtual = strlen(stringNomes);

    printf("Qual nome você quer adicionar?");
    scanf(" %[^\n]s", nome);

    tamanho = strlen(nome) + 1;

    pointer = &stringNomes[0];


    for (int i = 0; i < tamanho; i++){
        stringNomes[tamanhoAtual] = nome[i];
        tamanhoAtual++;
    }

    stringNomes[tamanhoAtual + 1] = '$';
}



int Remover(char stringNomes[], int ultimoIndex){
    int i = 0;
    char nomeComp[100];
    char nomeRem[100];

    printf("Qual nome você deseja remover?\n");
    scanf(" %[^\n]s", nomeRem);

    for (j = 0; j < ultimoIndex; j++){
        while (stringNomes[i] != '$'){
            i = 0;
            nomeComp[i] == stringNomes[j];
            i++;
        }

        if ((strcmp(nomeComp, nomeRem)) == 0){
            int tamanhoRem = strlen(nomeRem);
            int inicioRem = i - tamanhoRem;

            for (x = i; x < tamanhoRem; x++)

        }
    }
}
