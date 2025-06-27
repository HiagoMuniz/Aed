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
    int i = tamanho - 1;
    int top = 0;
    char *stack = malloc ((tamanho) * sizeof(char));
    int points = 0;

        if ( x > y ){

            while ( i >= 0 ){

            stack[top++] = s[i];

            if ( top > 2 && stack[top-1] == 'a' && stack[top-2] == 'b'){
                top += -2;
                points += x;
            }

            i--;
            }

            for ( int j = 0; j < top-1; j++ ){
                if ( stack[j] == 'a' && stack[j+1] == 'b' ){
                    points += y;
                }
            }
        }else{

            while ( i >= 0 ){

            stack[top++] = s[i];

            if ( top > 2 && stack[top-1] == 'b' && stack[top-2] == 'a'){
                top += -2;
                points += y;
            }

            i--;
            }

            for ( int j = 0; j < top-1; j++ ){
                if ( stack[j] == 'b' && stack[j+1] == 'a' ){
                    points += x;
                }
            }
        }


    return points;    

}


/* 

    for ( int i = 0; i < tamanho; i++){
        stack[top++] = s[i];

        if ( x > y ){
            if ( top >= 2 && stack[top-2] == 'a' && stack[top-1] == 'b'){
                points += x;
                top -= 2;
            } else if (  top > 3 && stack[top-3] == 'b'  && stack[top-2] == 'a' && stack[top-1] != 'b' ){
                points += y;
                top -= 2;
            }
        }else{
            if ( top >= 2 && stack[top-2] == 'b' && stack[top-1] == 'a'){
                points += x;
                top -= 2;
            } else if (  top > 3 && stack[top-3] == 'a'  && stack[top-2] == 'b' && stack[top-1] != 'a' ){
                points += y;
                top -= 2;
            }
        }
}    


        //////////////////////////////////////////


        if (  x > y ){
                if ( top > 2 && stack[top-1] == 'a' && stack[top-2] == 'b' ){
                    top += -2;
                    points += x;
                }else if( top > 3 && stack[top-2] == 'b' && stack[top-3] == 'a' && stack[top-1] != 'a'){
                    top += -2;
                    points += y;
                }
             }else{
                if ( top > 2 && stack[top-1] == 'b' && stack[top-2] == 'a' ){
                    top += -2;
                    points += x;
                }else if ( top > 3 && stack[top-2] == 'a' && stack[top-3] == 'b' && stack[top-1] != 'b'){
                    top += -2;
                    points += y;
                }
             }
                
            i--;
        }
*/