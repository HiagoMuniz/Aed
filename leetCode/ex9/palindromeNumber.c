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