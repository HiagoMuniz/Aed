char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int i = 0, j = 0, l = 0;
    char **goodWord = NULL;
    int count = 0;
    char *goodPlaca = NULL;

    int tamanhoPlate = strlen(licensePlate);

    for ( i = 0; i < tamanhoPlate; i++ ){
        if ((licensePlate[i] >= 'A' && licensePlate[i] <= 'Z') ||
            (licensePlate[i] >= 'a' && licensePlate[i] <= 'z')){

            goodPlaca = (char *) realloc(goodPlaca, sizeof(char) * (j+1));
            goodPlaca[j] = tolower(licensePlate[i]);
            j++;

        }
    }
    goodPlaca = (char *) realloc(goodPlaca, sizeof(char) * (j+1));
    goodPlaca[j] = '\0';

    tamanhoPlate = j;
    j = 0;

    for ( i = 0; i < wordsSize; i++){
        count = 0;
        char *tempPlaca = malloc(sizeof(char) * tamanhoPlate + 1);
        strcpy(tempPlaca, goodPlaca);

        for (j = 0; j < strlen(words[i]); j++){
            for (int k = 0; k < tamanhoPlate; k++){
                if (tempPlaca[k] == words[i][j]){
                    count++;
                    tempPlaca[k] = '$';
                    break;
                }
            }
        }

        free(tempPlaca);

        if (count == tamanhoPlate){
            goodWord = (char **) realloc(goodWord, (sizeof(char*) * (l+1)));
            goodWord[l] = (char *) malloc( sizeof(char) * (strlen(words[i]) + 1));
            strcpy(goodWord[l], words[i]);
            l++;
        }
    }

    if (l == 0) {
        free(goodPlaca);
        return NULL;
    }

    char *menorWord = goodWord[0];

    for ( i = 1; i < l; i++){
        if (strlen(goodWord[i]) < strlen(menorWord)){
            menorWord = goodWord[i];
        }
    }

    char *resultado = malloc(sizeof(char) * (strlen(menorWord) + 1) );
    strcpy(resultado, menorWord);

    for (i = 0; i < l; i++){
        free(goodWord[i]);
    }

    free(goodPlaca);
    free(goodWord);

    return resultado;

}

/*
            for (int k = 0; k < tamanhoPlate; k++){
                if (licensePlate[k] == words[i][j] || licensePlate[k] == '$'){
                    count++;
                }
            }
*/