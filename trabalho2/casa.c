#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maximumGain(char* s, int x, int y);

int main(void){
    char s[20] = "cdbcbbaaabab";
    int x = 4;
    int y = 5;

    int result = maximumGain(s, x, y);

    printf("%d", result);
}

int maximumGain(char* s, int x, int y) {
    int tamanho = strlen(s);
    int i = 0;
    int top = 0;
    char *stack = malloc ((tamanho) * sizeof(char));
    int points = 0;
    char *temp = NULL;

    if ( x > y ){

        while ( i < tamanho ){

        stack[top++] = s[i];

            if ( top >= 2 && stack[top-1] == 'b' && stack[top-2] == 'a'){
                top += -2;
                points += x;
            }

            i++;
            }

            temp = malloc(top * sizeof(char));
            int top2 = 0;
            for (int j = 0; j < top; j++) {
                temp[top2++] = stack[j];
                if (top2 >= 2 && temp[top2 - 2] == 'b' && temp[top2 - 1] == 'a') {
                    top2 -= 2;
                    points += y;
                }
            }
            free(temp);
        }else{

            while ( i < tamanho ){

            stack[top++] = s[i];

            if ( top >= 2 && stack[top-1] == 'a' && stack[top-2] == 'b'){
                top += -2;
                points += y;
            }

            i++;
            }

            temp = malloc(top * sizeof(char));
            int top2 = 0;
            for (int j = 0; j < top; j++) {
                temp[top2++] = stack[j];
                if (top2 >= 2 && temp[top2 - 2] == 'a' && temp[top2 - 1] == 'b') {
                    top2 -= 2;
                    points += x;
                }
            }
            free(temp);
        }

    free(stack);
    return points;    
}