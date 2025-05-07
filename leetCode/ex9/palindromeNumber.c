#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x);

int main(){
    int numero = -121;

    if (isPalindrome(numero)){
        printf("is palindrome");
    }else{
        printf("is not palindrome");
    }
}


bool isPalindrome(int x) {
    int invertido = 0;

    if ( x < 0 ){
        return false;
    }

    int num = x;

    while ( num != 0 ){
        int digito = num % 10;
        invertido = invertido * 10 + digito;
        num /= 10;
    }

    if ( x != invertido ){
        return false;
    }
    
    return true;
    
}