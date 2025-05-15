#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main() {

    char *palavras[] = {"dog", "car", "plane"};
    int tamanho = sizeof(palavras) / sizeof(palavras[0]);

    char *prefixo = longestCommonPrefix(palavras, tamanho);

    printf("Prefixo comum: \"%s\"\n", prefixo);

    free(prefixo); 

    return 0;
}


char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0, j = 0, x = 0, controle = 1;
    char *vec = NULL;

    int menor = strlen(strs[0]);

    for (i = 1; i < strsSize; i++){
        if (strlen(strs[i]) < menor){
            menor = strlen(strs[i]);
        }
    }


    for ( i = 0; i < menor; i++ ){
        controle = 0;
        for ( j = 1; j < strsSize; j++){
            if (strs[j][i] == strs[0][i]){
                controle++;
            }    
        }


         if (controle == strsSize-1){
            vec = (char *) realloc(vec, sizeof(char) * (x+2));
            vec[x] = strs[0][i];
            x++;
            vec[x] = '\0';
        }else{
            break;
        }
    }

    if (vec == NULL){
        vec = (char *) realloc(vec, sizeof(char) * (1));
        vec[0] = '\0';
    }
    return vec;
}
