bool areOccurrencesEqual(char* s) {
    int i = 0, j = 0;
    char *pointer = s;
    int count = 0;

    int tamanho = strlen(s);

    int vect[tamanho];

    for ( i = 0; i < tamanho; i++ ){
        vect[i] = 0;
    }


    for ( i = 0; i < tamanho; i++ ){
        for ( j = 0; j < tamanho; j++ ){
            if ( pointer[i] == pointer[j]){
                vect[i] += 1;
            }
        }
    }

    for ( i = 0; i < tamanho; i++ ){
        for ( j = 0; j < tamanho; j++ ){
            if (vect[i] != vect[j]){
                return false;
            }
        }
    }

return true;
}