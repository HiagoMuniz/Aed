#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char *pointer;
    int tamString, i=0;
    char c;

    scanf("%d", &tamString);
    getchar();

    pointer = (char*) malloc(sizeof(char) * (tamString + 1));

    for (i = 0; i < tamString;){
        scanf("%c", &c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            c = ' ';
        }
        pointer[i] = c;
        i++;
    }
    pointer[i] = '\0';

    printf("%s", pointer);

}